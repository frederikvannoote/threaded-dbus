#include "dbushandler.h"
#include "myobject.h"
#include "myobjectapi.h"
#include "myobjectapiadaptor.h"


DBusHandler::DBusHandler(MyObject &myObject, QObject *parent) :
    QObject(parent),
    m_myObject(myObject)
{
}

void DBusHandler::start()
{
    // Create this API object which converts the interface of MyObject
    // into something d-bus friendly.
    MyObjectAPI *myObjectApi = new MyObjectAPI(m_myObject);
    new ExampleAdaptor(myObjectApi);

    QDBusConnection::sessionBus().registerObject("/example", myObjectApi);
    QDBusConnection::sessionBus().registerService("org.example");
}
