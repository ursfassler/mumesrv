// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef SYSFSREADERDUMMY_HPP
#define SYSFSREADERDUMMY_HPP

#include <ISysfs.hpp>

class SysfsReaderDummy :
    public ISysfsReader
{
  public:
    QString read_return{};
    QString read() const override;

};

#endif // SYSFSREADERDUMMY_HPP
