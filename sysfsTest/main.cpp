// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include <SysfsValue.hpp>

#include <iostream>
#include <vector>
#include <string>

int main()
{
  const std::vector<std::string> files{
    "/sys/class/tty/tty/dev",
    "/sys/class/tty/tty/uevent"
  };

  for (const auto &file : files) {
    const SysfsValue sysfs{file};

    std::cout << "-- " << file << " --" << std::endl;
    std::cout << sysfs.read() << std::endl;
    std::cout << std::endl;
  }

  return 0;
}

