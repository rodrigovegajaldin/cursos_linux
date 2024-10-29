from gi.repository import Gio, GLib

bus_type = Gio.BusType.SYSTEM
bus_name = 'org.bluez'
object_path = '/org/bluez/hci0'
prop_iface = 'org.freedesktop.DBus.Properties'
adapter_iface = 'org.bluez.Adapter1'


adapter_props_proxy = Gio.DBusProxy.new_for_bus_sync(
            bus_type=bus_type,
            flags=Gio.DBusProxyFlags.NONE,
            info=None,
            name=bus_name,
            object_path=object_path,
            interface_name=prop_iface,
            cancellable=None)

all_props = adapter_props_proxy.GetAll('(s)', adapter_iface)
print(all_props)
powered = adapter_props_proxy.Get('(ss)', adapter_iface, 'Powered')
print(powered)
adapter_props_proxy.Set('(ssv)',
                        adapter_iface,
                        'Powered',
                        GLib.Variant.new_boolean(False)
                        )
powered = adapter_props_proxy.Get('(ss)', adapter_iface, 'Powered')
print(powered)
adapter_props_proxy.Set('(ssv)',
                        adapter_iface,
                        'Powered',
                        GLib.Variant.new_boolean(True)
                        )
powered = adapter_props_proxy.Get('(ss)', adapter_iface, 'Powered')
print(powered)
