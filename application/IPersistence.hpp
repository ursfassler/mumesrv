// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef IPERSISTENCE_H
#define IPERSISTENCE_H

#include <QString>

class IPersistence
{
  public:
    virtual ~IPersistence() = default;

    virtual QString read(QString section, QString key) const = 0;
    virtual void write(QString section, QString key, QString value) = 0;
};

#endif // IPERSISTENCE_H
