QT += dbus core
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    myobject.cpp \
    myobjectapi.cpp \
    myobjectapiadaptor.cpp \
    dbushandler.cpp

HEADERS += \
    myobject.h \
    myobjectapi.h \
    myobjectapiadaptor.h \
    dbushandler.h

generateXml.target = myobjectapi.xml
generateXml.commands = cd $$PWD; qdbuscpp2xml myobjectapi.h -o myobjectapi.xml
generateXml.depends = FORCE

generateAdaptor.target = myobjectapiadaptor.h
generateAdaptor.commands = cd $$PWD; qdbusxml2cpp -a myobjectapiadaptor myobjectapi.xml
generateAdaptor.depends = generateXml

QMAKE_EXTRA_TARGETS += generateXml generateAdaptor
PRE_TARGETDEPS += myobjectapi.xml myobjectapiadaptor.h
