// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "Application.hpp"

Application::Application(IPersistence &aPersistence, IMumeSrv &aMumeSrv) :
  persistence{aPersistence},
  mumeSrv{aMumeSrv}
{
  QObject::connect(&aMumeSrv, SIGNAL(openPositionChanged(double)), this, SLOT(setOpenPosition(double)));
}

void Application::init()
{
  const auto textValue = persistence.read("servo_open_pos_ns");
  bool ok = false;
  const auto value = textValue.toDouble(&ok);
  if (ok) {
    mumeSrv.setOpenPosition(value);
  }
}

void Application::setOpenPosition(double value)
{
  persistence.write("servo_open_pos_ns", QString::number(value, 'f', 9));
}
