#ifndef MYOBJECTAPI_H
#define MYOBJECTAPI_H

#include <QObject>
class MyObject;


class MyObjectAPI : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.example")

public:
    explicit MyObjectAPI(MyObject &object, QObject *parent = nullptr);

    Q_INVOKABLE void someMethod();

private:
    MyObject &m_object;
};

#endif // MYOBJECTAPI_H
