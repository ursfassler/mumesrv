// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "PersistenceDummy.hpp"

PersistenceDummy::PersistenceDummy()
{
}

void PersistenceDummy::write(QString section, QString key, QString value)
{
  values[section][key] = value;
}


QString PersistenceDummy::read(QString section, QString key) const
{
  return values.value(section, {}).value(key, {});
}
