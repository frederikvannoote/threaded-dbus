#ifndef DBUSHANDLER_H
#define DBUSHANDLER_H

#include <QObject>
#include <QThread>
class MyObject;


class DBusHandler : public QObject
{
    Q_OBJECT
public:
    explicit DBusHandler(QObject *parent = nullptr);
    virtual ~DBusHandler();

    void start(MyObject &myObject);

private:
    QThread m_thread;
};

#endif // DBUSHANDLER_H
