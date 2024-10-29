import logging
from gi.repository import Gio, GLib, GObject

# DBus Information
bus_type = Gio.BusType.SYSTEM
BLUEZ_NAME = 'org.bluez'
ADAPTER_PATH = '/org/bluez/hci0'
PROP_IFACE = 'org.freedesktop.DBus.Properties'
ADAPTER_IFACE = 'org.bluez.Adapter1'
DEVICE_IFACE = 'org.bluez.Device1'

logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger('scan_app')


def create_variant(py_data):
    """
    convert python native data types to D-Bus variant types by looking up
    their type expected for that key.
    """
    type_lookup = {'Address': 's',
                   'AddressType': 's',
                   'Name': 's',
                   'Icon': 's',
                   'Class': 'u',
                   'Appearance': 'q',
                   'Alias': 's',
                   'Paired': 'b',
                   'Trusted': 'b',
                   'Blocked': 'b',
                   'LegacyPairing': 'b',
                   'RSSI': 'n',
                   'Connected': 'b',
                   'UUIDs': 'as',
                   'Adapter': 'o',
                   'ManufacturerData': 'a{qay}',
                   'ServiceData': 'a{say}',
                   'TxPower': 'n',
                   'ServicesResolved': 'b',
                   'WakeAllowed': 'b',
                   'Modalias': 's',
                   'AdvertisingFlags': 'ay',
                   'AdvertisingData': 'a{yay}',
                   'Powered': 'b',
                   'Discoverable': 'b',
                   'Pairable': 'b',
                   'PairableTimeout': 'u',
                   'DiscoverableTimeout': 'u',
                   'Discovering': 'b',
                   'Roles': 'as',
                   'ExperimentalFeatures': 'as',
                   }
    if py_data is None:
        return GLib.Variant('a{sv}', {})
    for k, v in py_data.items():
        py_data[k] = GLib.Variant(type_lookup[k], v)
    return GLib.Variant('a{sv}', py_data)


class BluezObjectManager(GObject.GObject):
    __gsignals__ = {
        'adapter-added': (GObject.SignalFlags.NO_HOOKS, None,
                          (str, GObject.TYPE_VARIANT)),
        'adapter-removed': (GObject.SignalFlags.NO_HOOKS, None, (str,)),
        'device-added': (GObject.SignalFlags.NO_HOOKS, None,
                         (str, GObject.TYPE_VARIANT)),
        'device-removed': (GObject.SignalFlags.NO_HOOKS, None, (str,)),
    }

    def __init__(self) -> None:
        super().__init__()
        self._object_manager = Gio.DBusObjectManagerClient.new_for_bus_sync(
            bus_type,
            Gio.DBusObjectManagerClientFlags.DO_NOT_AUTO_START,
            BLUEZ_NAME,
            '/', None, None, None)

        self._object_manager.connect("object-added", self._on_object_added)
        self._object_manager.connect("object-removed", self._on_object_removed)

    def _on_object_added(self,
                         _object_manager: Gio.DBusObjectManager,
                         dbus_object: Gio.DBusObject) -> None:
        object_path = dbus_object.get_object_path()
        ifaces = [iface.get_interface_name()
                  for iface in dbus_object.get_interfaces()]
        if ADAPTER_IFACE in ifaces:
            prop_proxy = dbus_object.get_interface(PROP_IFACE)
            adapter_props = prop_proxy.GetAll('(s)', ADAPTER_IFACE)
            logger.debug('adapter-added %s', object_path, adapter_props)
            self.emit('adapter-added', object_path, adapter_props)
        elif DEVICE_IFACE in ifaces:
            prop_proxy = dbus_object.get_interface(PROP_IFACE)
            dev_props = prop_proxy.GetAll('(s)', DEVICE_IFACE)
            logger.debug('device-added %s : %s', object_path, dev_props)
            self.emit('device-added', object_path, create_variant(dev_props))

    def _on_object_removed(self,
                           _object_manager: Gio.DBusObjectManager,
                           dbus_object: Gio.DBusObject) -> None:
        object_path = dbus_object.get_object_path()
        ifaces = [iface.get_interface_name()
                  for iface in dbus_object.get_interfaces()]
        if ADAPTER_IFACE in ifaces:
            logger.debug('adapter-removed %s : %s', object_path)
            self.emit('adapter-removed', object_path)
        elif DEVICE_IFACE in ifaces:
            logger.debug('device-removed: %s', object_path)
            self.emit('device-removed', object_path)


def bluez_proxy(object_path, interface):
    """Return a BlueZ proxy object for the given D-Bus information"""
    return Gio.DBusProxy.new_for_bus_sync(
        bus_type=bus_type,
        flags=Gio.DBusProxyFlags.NONE,
        info=None,
        name=BLUEZ_NAME,
        object_path=object_path,
        interface_name=interface,
        cancellable=None)


def new_device_hndlr(proxy: BluezObjectManager,
                     object_path: str,
                     device_props: GObject.TYPE_VARIANT) -> None:
    """Event handler for New device has been detected with scan"""
    props = device_props.unpack()
    logger.debug('New Device Handler: %s : %s', object_path, props)
    address = props.get('Address')
    if address:
        print(f'Device with address {address} found. '
              f'Removing from BlueZ cache')
    # adapter.RemoveDevice('(o)', GLib.Variant.new_object_path(object_path))
    adapter.RemoveDevice('(o)', object_path)


def stop_scan():
    """Stop scanning for new devices and quit event loop"""
    logger.info('Stopping Discovery')
    adapter.StopDiscovery()
    mainloop.quit()
    return False


if __name__ == '__main__':
    # setup dbus
    mngr = BluezObjectManager()
    adapter = bluez_proxy(ADAPTER_PATH, ADAPTER_IFACE)
    # Link device-added event to callback function
    mngr.connect('device-added', new_device_hndlr)
    # Start discovering (scanning) for devices
    adapter.StartDiscovery()

    # Enable eventloop for notifications
    mainloop = GLib.MainLoop()
    # Create a timed event to call the stop_scan function
    GLib.timeout_add_seconds(interval=20, function=stop_scan)

    try:
        mainloop.run()
    except KeyboardInterrupt:
        mainloop.quit()
        adapter.StopDiscovery()
