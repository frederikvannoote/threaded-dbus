#include <QCoreApplication>
#include <QDBusConnection>
#include <QThread>
#include "myobject.h"
#include "dbushandler.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Backend object running in the main thread
    MyObject myObject;

    // Umbrella object handling all dbus related stuff in it's own thread
    // (ref: https://codethis.wordpress.com/2011/04/04/using-qthread-without-subclassing/ )
    QThread dbusThread;
    dbusThread.setObjectName("DBus handling");
    DBusHandler dbus(myObject);
    dbus.moveToThread(&dbusThread);
    QObject::connect(&dbusThread, &QThread::started, &dbus, &DBusHandler::start);
    dbusThread.start();

    return a.exec();
}
