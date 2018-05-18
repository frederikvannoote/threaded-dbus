#include "dbushandler.h"
#include "myobject.h"
#include "myobjectapi.h"
#include "myobjectapiadaptor.h"


DBusHandler::DBusHandler(QObject *parent) :
    QObject(parent),
    m_thread()
{
    // Run this object in the context of it's own thread.
    m_thread.start();
    moveToThread(&m_thread);
}

DBusHandler::~DBusHandler()
{
    // Quit the thread and wait for it to join.
    m_thread.quit();
    m_thread.wait();
}

void DBusHandler::start(MyObject &myObject)
{
    // Create this API object which converts the interface of MyObject
    // into something d-bus friendly.
    MyObjectAPI *myObjectApi = new MyObjectAPI(myObject);
    new ExampleAdaptor(myObjectApi);

    QDBusConnection::sessionBus().registerObject("/example", myObjectApi);
    QDBusConnection::sessionBus().registerService("org.example");
}
