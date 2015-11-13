# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += xml

QMAKE_CXXFLAGS += --std=c++11

INCLUDEPATH += ../application/

LIBS += -lgtest -lgmock -lgtest_main

SOURCES += \
    MumeSrv_test.cpp \
    ../application/MumeSrv.cpp \
    Configuration_test.cpp \
    ../application/Configuration.cpp

HEADERS += \
    ../application/MumeSrv.hpp \
    mocks/SysfsReaderMock.hpp \
    ../application/Configuration.hpp

