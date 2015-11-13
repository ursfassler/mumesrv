// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "SysfsReaderDummy.hpp"

QString SysfsReaderDummy::read() const
{
  return read_return;
}

