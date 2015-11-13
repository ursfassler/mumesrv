// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef SYSFSVALUE_HPP
#define SYSFSVALUE_HPP

#include <ISysfs.hpp>

#include <QString>

class SysfsValue :
    public ISysfsReader
{
  public:
    SysfsValue(QString filename);

    QString read() const override;

  private:
    const QString filename;
};

#endif // SYSFSVALUE_HPP
