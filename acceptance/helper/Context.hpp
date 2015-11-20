// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef CONTEXT
#define CONTEXT

#include "SysfsReaderDummy.hpp"
#include "SysfsWriterDummy.hpp"
#include "PersistenceDummy.hpp"

#include <MumeSrv.hpp>
#include <Application.hpp>

class Context
{
  public:
    PersistenceDummy persistence;
    SysfsReaderDummy sysfsSwitch{};
    SysfsReaderDummy sysfsCount{};
    SysfsWriterDummy sysfsServoOpenPosNs{};
    SysfsWriterDummy sysfsServoClosePosNs{};
    MumeSrv mumeSrv{sysfsSwitch, sysfsCount, sysfsServoOpenPosNs, sysfsServoClosePosNs};
    Application application{persistence, mumeSrv};
};

#endif // CONTEXT

