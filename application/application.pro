# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

TARGET = mumeweb
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

QT -= gui
QT += dbus
QT += core

QMAKE_CXXFLAGS += --std=c++11

TEMPLATE = app

dbusAdaptor.target = dbusAdaptor
dbusAdaptor.commands = qdbusxml2cpp $$PWD/mumesrv.xml -a $$PWD/generated/MumeSrvAdaptor
QMAKE_EXTRA_TARGETS += dbusAdaptor
PRE_TARGETDEPS += dbusAdaptor

SOURCES += main.cpp \
    MumeSrv.cpp \
    generated/MumeSrvAdaptor.cpp \
    SysfsValue.cpp

HEADERS += \
    MumeSrv.hpp \
    generated/MumeSrvAdaptor.h \
    SysfsValue.hpp \
    ISysfs.hpp

DISTFILES += \
    mumesrv.xml
