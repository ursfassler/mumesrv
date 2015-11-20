// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "MumeSrv.hpp"

MumeSrv::MumeSrv(const ISysfsReader &aSysfsSwitch, ISysfsWriter &aSysfsServoOpenPosNs, QObject* parent) :
  IMumeSrv{parent},
  sysfsSwitch{aSysfsSwitch},
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
