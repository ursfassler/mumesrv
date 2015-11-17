// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "Persistence.hpp"

Persistence::Persistence() :
  storage{QSettings::NativeFormat, QSettings::SystemScope, "urs"}
{
}

QString Persistence::read(QString key) const
{
  return storage.value(key).toString();
}

void Persistence::write(QString key, QString value)
{
  storage.setValue(key, value);
}
