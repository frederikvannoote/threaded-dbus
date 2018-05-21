#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QMutex>


class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr);

    void someMethod();

    bool isLocked() const;

private:
    mutable QMutex m_mutex;
};

#endif // MYOBJECT_H
