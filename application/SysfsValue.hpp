// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef SYSFSVALUE_HPP
#define SYSFSVALUE_HPP

#include <ISysfs.hpp>

#include <string>

class SysfsValue :
    public ISysfsReader
{
  public:
    SysfsValue(const std::string &filename);

    std::string read() const override;

  private:
    const std::string filename;
};

#endif // SYSFSVALUE_HPP
