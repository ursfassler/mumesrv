// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "Persistence.hpp"

Persistence::Persistence() :
  storage{QSettings::NativeFormat, QSettings::SystemScope, "urs", "mumesrv"}
{
}

static QString seckey(QString section, QString key)
{
  return section + "/" + key;
}

QString Persistence::read(QString section, QString key) const
{
  return storage.value(seckey(section,key)).toString();
}

void Persistence::write(QString section, QString key, QString value)
{
  storage.setValue(seckey(section,key), value);
}
