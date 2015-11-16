// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "Configuration.hpp"

#include <QCommandLineParser>

Configuration::Configuration(QStringList arg)
{
  QCommandLineParser parser;
  QCommandLineOption sessionDbusOption("session-dbus");
  parser.addOption(sessionDbusOption);
  parser.addPositionalArgument("sysfs-root", "sysfs root path");

  valid = parser.parse(arg);

  const auto positional = parser.positionalArguments();
  valid = valid && positional.size() == 1;

  if (valid) {
    systemDbus = !parser.isSet(sessionDbusOption);
    sysfs = positional.first();
  } else {
    _helpText = parser.helpText();
  }
}

bool Configuration::isValid() const
{
  return valid;
}

QString Configuration::helpText() const
{
  return _helpText;
}

bool Configuration::useSystemDbus() const
{
  return systemDbus;
}

QString Configuration::sysfsRoot() const
{
  return sysfs;
}


