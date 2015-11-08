// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "SysfsValue.hpp"

#include <fstream>

SysfsValue::SysfsValue(const std::string &aFilename) :
  filename{aFilename}
{
}

std::string SysfsValue::read() const
{
  std::string content{""};

  std::ifstream file{filename, std::ifstream::in};

  while (file.good()) {
    char buffer[100];
    int n = file.readsome(buffer, sizeof(buffer)-1);
    if (n == 0) {
      break;
    }
    buffer[n] = '\0';
    content += buffer;
  }

  return content;
}

