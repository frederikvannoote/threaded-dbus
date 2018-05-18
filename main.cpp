#include <QCoreApplication>
#include <QDBusConnection>
#include "myobject.h"
#include "dbushandler.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Backend object running in the main thread
    MyObject myObject;

    // Umbrella object handling all dbus related stuff
    DBusHandler dbus;
    dbus.start(myObject);

    return a.exec();
}
