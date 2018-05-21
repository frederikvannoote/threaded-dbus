#pragma once

#include <QObject>
#include <QPointer>
class MyObject;


class DBusHandler : public QObject
{
    Q_OBJECT
public:
    explicit DBusHandler(MyObject &myObject, QObject *parent = nullptr);

    void start();

Q_SIGNALS:
    void finished();

private:
    MyObject &m_myObject;
};
