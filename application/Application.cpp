// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "Application.hpp"

Application::Application(IPersistence &aPersistence, IMumeSrv &aMumeSrv) :
  persistence{aPersistence},
  mumeSrv{aMumeSrv}
{
  QObject::connect(&aMumeSrv, SIGNAL(openPositionMsChanged(double)), this, SLOT(setOpenPositionMs(double)));
}

void Application::init()
{
  const auto textValue = persistence.read("servo", "open_pos_ms");
  bool ok = false;
  const auto value = textValue.toDouble(&ok);
  if (ok) {
    mumeSrv.setOpenPositionMs(value);
  }
}

void Application::setOpenPositionMs(double value)
{
  persistence.write("servo", "open_pos_ms", QString::number(value, 'f', 6));
}
