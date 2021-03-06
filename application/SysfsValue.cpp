// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "SysfsValue.hpp"

#include <fstream>

SysfsRoValue::SysfsRoValue(QString aFilename) :
  filename{aFilename}
{
}

QString SysfsRoValue::read() const
{
  QString content{""};

  std::ifstream file{filename.toStdString(), std::ifstream::in};

  while (file.good()) {
    char buffer[100];
    int n = file.readsome(buffer, sizeof(buffer)-1);
    if (n == 0) {
      break;
    }
    buffer[n] = '\0';
    content += buffer;
  }

  return content.trimmed();
}


SysfsWoValue::SysfsWoValue(QString aFilename) :
  filename{aFilename}
{
}

void SysfsWoValue::write(QString value)
{
  const std::string content{value.toStdString() + "\n"};

  std::ofstream file{filename.toStdString(), std::ifstream::out};

  file.write(content.c_str(), content.size());
}
