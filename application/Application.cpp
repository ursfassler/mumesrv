// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "Application.hpp"

Application::Application(IPersistence &aPersistence, IMumeSrv &aMumeSrv) :
  persistence{aPersistence},
  mumeSrv{aMumeSrv}
{
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
