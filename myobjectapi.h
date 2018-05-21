#ifndef MYOBJECTAPI_H
#define MYOBJECTAPI_H

#include <QObject>
class MyObject;


class MyObjectAPI : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.example")
    Q_PROPERTY(bool locked READ isLocked)

public:
    explicit MyObjectAPI(MyObject &object, QObject *parent = nullptr);

    Q_INVOKABLE void someMethod();
    Q_INVOKABLE bool isLocked() const;

private:
    MyObject &m_object;
};

#endif // MYOBJECTAPI_H
