# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

QT += xml

QMAKE_CXXFLAGS += --std=c++11

INCLUDEPATH += ../application/

LIBS += -lgtest -lcucumber-cpp -lboost_regex -lboost_system

SOURCES += \
    ../application/MumeSrv.cpp \
    features/step_definitions/DbusSteps.cpp \
    features/step_definitions/SysfsSteps.cpp \
    helper/SysfsReaderDummy.cpp

DISTFILES += \
    features/step_definitions/cucumber.wire \
    features/read_state_of_switch.feature

HEADERS += \
    ../application/MumeSrv.hpp \
    helper/Context.hpp \
    helper/SysfsReaderDummy.hpp
