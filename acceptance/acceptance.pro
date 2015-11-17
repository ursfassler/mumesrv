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
    helper/SysfsReaderDummy.cpp \
    helper/SysfsWriterDummy.cpp \
    features/step_definitions/PersistenceSteps.cpp \
    features/step_definitions/ServiceSteps.cpp \
    helper/PersistenceDummy.cpp \
    ../application/Application.cpp \
    ../application/IMumeSrv.cpp

DISTFILES += \
    features/step_definitions/cucumber.wire \
    features/read_state_of_switch.feature \
    features/write_servo_end_positions.feature

HEADERS += \
    ../application/MumeSrv.hpp \
    helper/Context.hpp \
    helper/SysfsReaderDummy.hpp \
    helper/SysfsWriterDummy.hpp \
    helper/PersistenceDummy.hpp \
    ../application/Application.hpp \
    ../application/IMumeSrv.hpp

OTHER_FILES += \
    features/persistent_servo_end_positions.feature
