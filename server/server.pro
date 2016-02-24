#-------------------------------------------------
#
# Project created by QtCreator 2016-02-18T13:23:13
#
#-------------------------------------------------

QT       += core network

TARGET = server
TEMPLATE = app
CONFIG += c++11

macx {
    QMAKE_MAC_SDK = macosx10.11
    QMAKE_CXXFLAGS  += -Wno-inconsistent-missing-override
}

SOURCES += \
    src/main.cpp \
    src/console/consolehandler.cpp \
    src/calculation/calculationmanager.cpp \
    src/network/networkmanager.cpp \
    src/calculation/calculation.cpp \
    src/network/clientsession.cpp \
    src/utils/abstractidentifiable.cpp \
    src/utils/logger.cpp \
    src/applicationmanager.cpp \
    src/plugins/pluginmanager.cpp \
    src/network/udpserver.cpp \
    src/network/tcpserver.cpp \
    src/network/etat/abstractstate.cpp \
    src/network/etat/disconnectedstate.cpp \
    src/network/etat/readystate.cpp \
    src/network/etat/waitingstate.cpp \
    src/network/etat/workingabouttostartstate.cpp \
    src/network/etat/workingstate.cpp \
    src/plugins/calculationprocess.cpp

HEADERS  += \
    src/console/consolehandler.h \
    src/calculation/calculationmanager.h \
    src/network/networkmanager.h \
    src/calculation/calculation.h \
    src/network/clientsession.h \
    src/const.h \
    src/utils/abstractidentifiable.h \
    src/utils/logger.h \
    src/applicationmanager.h \
    src/plugins/pluginmanager.h \
    src/network/udpserver.h \
    src/network/tcpserver.h \
    src/network/etat/abstractstate.h \
    src/network/etat/disconnectedstate.h \
    src/network/etat/readystate.h \
    src/network/etat/waitingstate.h \
    src/network/etat/workingabouttostartstate.h \
    src/network/etat/workingstate.h \
    src/calculation/specs.h \
    src/plugins/calculationprocess.h

FORMS    +=
