// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "SysfsWriterDummy.hpp"


void SysfsWriterDummy::write(QString value)
{
  content = value;
}
