// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "PersistenceDummy.hpp"

PersistenceDummy::PersistenceDummy()
{
}

void PersistenceDummy::write(QString key, QString value)
{
  values[key] = value;
}


QString PersistenceDummy::read(QString key) const
{
  return values.value(key, {});
}
