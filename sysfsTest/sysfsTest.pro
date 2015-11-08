# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../application

SOURCES += main.cpp \
    ../application/SysfsValue.cpp

HEADERS += \
    ../application/SysfsValue.hpp

