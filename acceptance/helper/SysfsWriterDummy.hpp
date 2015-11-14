// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef SYSFSWRITERDUMMY_HPP
#define SYSFSWRITERDUMMY_HPP

#include <ISysfs.hpp>

#include <QString>

class SysfsWriterDummy :
    public ISysfsWriter
{
  public:
    QString content{""};
    void write(QString value) override;



};

#endif // SYSFSWRITERDUMMY_HPP
