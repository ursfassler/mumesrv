// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef ISYSFS
#define ISYSFS

#include <string>

class ISysfsReader
{
  public:
    virtual ~ISysfsReader() = default;

    virtual std::string read() const = 0;
};

#endif // ISYSFS

