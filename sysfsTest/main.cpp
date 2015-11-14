// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include <SysfsValue.hpp>

#include <iostream>
#include <QList>
#include <QString>

int main()
{
  const QList<QString> files{
    "/sys/class/tty/tty/dev",
    "/sys/class/tty/tty/uevent"
  };

  for (const auto &file : files) {
    const SysfsRoValue sysfs{file};

    std::cout << "-- " << file.toStdString() << " --" << std::endl;
    std::cout << sysfs.read().toStdString() << std::endl;
    std::cout << std::endl;
  }

  return 0;
}

