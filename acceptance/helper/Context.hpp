// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef CONTEXT
#define CONTEXT

#include "SysfsReaderDummy.hpp"

#include <MumeSrv.hpp>

class Context
{
  public:
    SysfsReaderDummy sysfsSwitch{};
    MumeSrv mumeSrv{sysfsSwitch};
};

#endif // CONTEXT

