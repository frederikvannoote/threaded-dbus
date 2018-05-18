#include "myobject.h"
#include <QDebug>


MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::someMethod()
{
    qDebug() << "called MyObject::someMethod";
}
