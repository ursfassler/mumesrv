// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "MumeSrv.hpp"

MumeSrv::MumeSrv(const ISysfsReader &aSysfsSwitch, QObject* parent) :
  QObject(parent),
  sysfsSwitch{aSysfsSwitch}
{
}

bool MumeSrv::isSwitchOn()
{
  const auto content = QString::fromStdString(sysfsSwitch.read()).trimmed();
  return content == "on";
}


