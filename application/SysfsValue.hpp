// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef SYSFSVALUE_HPP
#define SYSFSVALUE_HPP

#include <ISysfs.hpp>

#include <QString>

class SysfsRoValue :
    public ISysfsReader
{
  public:
    SysfsRoValue(QString filename);

    QString read() const override;

  private:
    const QString filename;
};

class SysfsWoValue :
    public ISysfsWriter
{
  public:
    SysfsWoValue(QString filename);

    void write(QString value) override;

  private:
    const QString filename;
};

#endif // SYSFSVALUE_HPP
