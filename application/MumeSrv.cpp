// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "MumeSrv.hpp"

MumeSrv::MumeSrv(const ISysfsReader &aSysfsSwitch, const ISysfsReader &aSysfsCount, ISysfsWriter &aSysfsServoOpenPosNs, ISysfsWriter &aSysfsServoClosePosNs, QObject* parent) :
  IMumeSrv{parent},
  sysfsSwitch{aSysfsSwitch},
  sysfsCount{aSysfsCount},
  sysfsServoOpenPosNs{aSysfsServoOpenPosNs},
  sysfsServoClosePosNs{aSysfsServoClosePosNs}
{
}

static QString nsFromMs(double value)
{
  const quint32 ns = value * 1000*1000;
  return QString::number(ns);
}

void MumeSrv::setOpenPositionMs(double value)
{
  sysfsServoOpenPosNs.write(nsFromMs(value));
  openPositionMsChanged(value);
}

void MumeSrv::setClosePositionMs(double value)
{
  sysfsServoClosePosNs.write(nsFromMs(value));
  closePositionMsChanged(value);
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
