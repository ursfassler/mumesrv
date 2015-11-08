// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef MUMESRV_HPP
#define MUMESRV_HPP

#include "ISysfs.hpp"

#include <QObject>

class MumeSrv :
    public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool switchOn READ isSwitchOn())

  public:
    MumeSrv(const ISysfsReader &sysfsSwitch, QObject* parent = 0);

  private:
    const ISysfsReader &sysfsSwitch;

    bool isSwitchOn();

};

#endif // MUMESRV_HPP
