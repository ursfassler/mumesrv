// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "MumeSrv.hpp"
#include "SysfsValue.hpp"
#include "Configuration.hpp"
#include "generated/MumeSrvAdaptor.h"

#include <QCoreApplication>
#include <QDBusConnection>
#include <QCommandLineParser>
#include <iostream>

static void registerAtDbus(QDBusConnection dbus, MumeSrv *srv)
{
  new MumeSrvAdaptor(srv);
  dbus.registerObject("/ch/bitzgi/mumesrv", srv);
  dbus.registerService("ch.bitzgi.MumeSrv");
}

static QDBusConnection getBus(bool useSystemBus)
{
  if (useSystemBus) {
    return QDBusConnection::systemBus();
  } else {
    return QDBusConnection::sessionBus();
  }
}

int main(int argc, char *argv[])
{
  QCoreApplication a{argc, argv};
  Configuration configuration{a.arguments()};

  if (!configuration.isValid()) {
    std::cout << configuration.helpText().toStdString() << std::endl;
    return -1;
  }

  SysfsValue sysfsSwitch{configuration.sysfsRoot() + "/switch"};
  MumeSrv mumesrv{sysfsSwitch, &a};

  auto bus = getBus(configuration.useSystemDbus());
  registerAtDbus(bus, &mumesrv);

  return a.exec();
}

