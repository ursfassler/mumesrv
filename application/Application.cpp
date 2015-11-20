// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "Application.hpp"

Application::Application(IPersistence &aPersistence, IMumeSrv &aMumeSrv) :
  persistence{aPersistence},
  mumeSrv{aMumeSrv}
{
  QObject::connect(&aMumeSrv, SIGNAL(openPositionMsChanged(double)), this, SLOT(setOpenPositionMs(double)));
  QObject::connect(&aMumeSrv, SIGNAL(closePositionMsChanged(double)), this, SLOT(setClosePositionMs(double)));
}

void Application::init()
{
  loadValue("open_pos_ms", &IMumeSrv::setOpenPositionMs);
  loadValue("close_pos_ms", &IMumeSrv::setClosePositionMs);
}

void Application::loadValue(QString key, std::function<void(IMumeSrv &, double)> writer)
{
  const auto textValue = persistence.read("servo", key);
  bool ok = false;
  const auto value = textValue.toDouble(&ok);
  if (ok) {
    writer(mumeSrv, value);
  }
}


void Application::setOpenPositionMs(double value)
{
  persistence.write("servo", "open_pos_ms", QString::number(value, 'f', 6));
}

void Application::setClosePositionMs(double value)
{
  persistence.write("servo", "close_pos_ms", QString::number(value, 'f', 6));
}
