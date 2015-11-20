// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "MumeSrv.hpp"

MumeSrv::MumeSrv(const ISysfsReader &aSysfsSwitch, const ISysfsReader &aSysfsCount, ISysfsWriter &aSysfsServoOpenPosNs, QObject* parent) :
  IMumeSrv{parent},
  sysfsSwitch{aSysfsSwitch},
  sysfsCount{aSysfsCount},
  sysfsServoOpenPosNs{aSysfsServoOpenPosNs}
{
}

void MumeSrv::setOpenPositionMs(double value)
{
  const quint32 ns = value * 1000*1000;
  const QString str = QString::number(ns);

  sysfsServoOpenPosNs.write(str);
  openPositionMsChanged(value);
}

bool MumeSrv::isSwitchOn()
{
  const auto content = sysfsSwitch.read();
  return content == "on";
}

uint MumeSrv::count()
{
  const auto content = sysfsCount.read();
  return content.toUInt();
}
