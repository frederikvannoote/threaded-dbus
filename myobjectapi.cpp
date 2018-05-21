#include "myobjectapi.h"
#include "myobject.h"


MyObjectAPI::MyObjectAPI(MyObject &object, QObject *parent):
    QObject(parent),
    m_object(object)
{
}

void MyObjectAPI::someMethod()
{
    m_object.someMethod();
}

bool MyObjectAPI::isLocked() const
{
    return m_object.isLocked();
}
