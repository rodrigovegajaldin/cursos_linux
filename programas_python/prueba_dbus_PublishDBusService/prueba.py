import logging
from math import sqrt

from gi.repository import Gio, GLib, GObject

logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger('calc')


def _build_variant(name, py_value):
    s_data = GLib.VariantDict.new()
    for key, value in py_value.items():
        gvalue = GLib.Variant('ay', value)
        s_data.insert_value(key, gvalue)
    return s_data.end()


class DbusService:

    def __init__(self, introspection_xml, publish_path, 
                 own_name=None, sys_bus=True):
        self.node_info = Gio.DBusNodeInfo.new_for_xml(introspection_xml).interfaces[0]
        method_outargs = {}
        method_inargs = {}
        property_sig = {}
        for method in self.node_info.methods:
            method_outargs[method.name] = '(' + ''.join([arg.signature for arg in method.out_args]) + ')'
            method_inargs[method.name] = tuple(arg.signature for arg in method.in_args)
        self.method_inargs = method_inargs
        self.method_outargs = method_outargs
        if sys_bus:
            self.con = Gio.bus_get_sync(Gio.BusType.SYSTEM, None)
        else:
            self.con = Gio.bus_get_sync(Gio.BusType.SESSION, None)
        if own_name:
            Gio.bus_own_name_on_connection(connection=self.con,
                                           name=own_name,
                                           flags=Gio.BusNameOwnerFlags.NONE,
                                           name_acquired_closure=None,
                                           name_lost_closure=None)
        self.con.register_object(
            publish_path,
            self.node_info,
            self.handle_method_call,
            self.prop_getter,
            self.prop_setter)

    def handle_method_call(self,
                           connection: Gio.DBusConnection,
                           sender: str,
                           object_path: str,
                           interface_name: str,
                           method_name: str,
                           params: GLib.Variant,
                           invocation: Gio.DBusMethodInvocation
                           ):
        """
        This is the top-level function that handles method calls to
        the server.
        """
        args = list(params.unpack())
        for i, sig in enumerate(self.method_inargs[method_name]):
            # Check if there is a Unix file descriptor  in the signature
            if sig == 'h':
                msg = invocation.get_message()
                fd_list = msg.get_unix_fd_list()
                args[i] = fd_list.get(args[i])
        # Get the method from the Python class
        func = self.__getattribute__(method_name)
        result = func(*args)
        if result is None:
            result = ()
        else:
            result = (result,)
        outargs = ''.join([_.signature
                           for _ in invocation.get_method_info().out_args])
        send_result = GLib.Variant(f'({outargs})', result)
        logger.debug('Method %s result: %s', method_name, repr(send_result))
        invocation.return_value(send_result)

    def prop_getter(self,
                    connection: Gio.DBusConnection,
                    sender: str,
                    object: str,
                    iface: str,
                    name: str):
        """Mehtod for moving properties from Python Class to D-Bus"""
        logger.debug('prop_getter, %s, %s, %s, %s, %s',
                     connection, sender, object, iface, name)
        py_value = self.__getattribute__(name)
        signature = self.node_info.lookup_property(name).signature
        if 'v' in signature:
            dbus_value = _build_variant(name, py_value)
            return dbus_value
        if py_value:
            return GLib.Variant(signature, py_value)
        return None

    def prop_setter(self,
                    connection: Gio.DBusConnection,
                    sender: str,
                    object: str,
                    iface: str,
                    name: str,
                    value: GLib.Variant):
        """Method for moving properties between D-Bus and Python Class"""
        logger.debug('prop_setter %s, %s, %s, %s, %s, %s',
                     connection, sender, object, iface, name, value)
        self.__setattr__(name, value.unpack())
        return True


class MyDBusService(DbusService):
    introspection_xml = """
        <!DOCTYPE node PUBLIC
        "-//freedesktop//DTD D-BUS Object Introspection 1.0//EN"
        "http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd">
        <node>
            <interface name="org.ukbaz.calculator1">
                <method name="Fibonacci">
                    <arg type="q" name="position" direction="in"/>
                    <arg type="t" name="result" direction="out"/>
                </method>
                <property name="limit" type="t" access="read"/>
            </interface>
        </node>
        """

    def __init__(self):
        self.path = '/org/ukbaz/fibonacci0001'
        super().__init__(self.introspection_xml, self.path,
                         own_name='org.ukbaz', sys_bus=False)
        self.limit = 94

    def Fibonacci(self, position):
        return round(
            (((1 + sqrt(5)) / 2) ** position - (
                    (1 - sqrt(5)) / 2) ** position) / sqrt(5))


def main():
    service = MyDBusService()
    mainloop = GLib.MainLoop()
    try:
        mainloop.run()
    except KeyboardInterrupt:
        mainloop.quit()


if __name__ == '__main__':
    main()

