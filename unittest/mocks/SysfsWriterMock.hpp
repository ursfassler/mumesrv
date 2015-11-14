// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef SYSFSWRITERMOCK
#define SYSFSWRITERMOCK

#include <ISysfs.hpp>

#include <gmock/gmock.h>

class SysfsWriterMock :
    public ISysfsWriter
{
  public:
    MOCK_METHOD1(write, void(QString));
};

#endif // SYSFSWRITERMOCK

