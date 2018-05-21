#include "myobject.h"
#include <QDebug>
#include <QMutexLocker>
#include <QThread>


MyObject::MyObject(QObject *parent):
    QObject(parent),
    m_mutex()
{
}

void MyObject::someMethod()
{
    QMutexLocker locker(&m_mutex);
    qDebug() << "called MyObject::someMethod";

    for (int i=0; i<10; i++)
    {
        qDebug() << ".";
        QThread::sleep(1);
    }

    qDebug() << "finished MyObject::someMethod";
}

bool MyObject::isLocked() const
{
    qDebug() << "called MyObject::isLocked";

    bool canLock = m_mutex.tryLock();
    if (canLock)
    {
        m_mutex.unlock();
    }

    qDebug() << "finished MyObject::isLocked:" << !canLock;

    return !canLock;
}
