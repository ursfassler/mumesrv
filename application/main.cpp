// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "MumeSrv.hpp"
#include "SysfsValue.hpp"
#include "generated/MumeSrvAdaptor.h"

#include <QCoreApplication>
#include <QDBusConnection>

static void registerAtDbus(MumeSrv *srv)
{
  new MumeSrvAdaptor(srv);
  QDBusConnection dbus = QDBusConnection::sessionBus();
  dbus.registerObject("/ch/bitzgi/mumesrv", srv);
  dbus.registerService("ch.bitzgi.MumeSrv");
}

int main(int argc, char *argv[])
{
  QCoreApplication a{argc, argv};

  SysfsValue sysfsSwitch{"/sys/bus/platform/devices/mume/switch"};
  MumeSrv mumesrv{sysfsSwitch, &a};
  registerAtDbus(&mumesrv);

  return a.exec();
}

