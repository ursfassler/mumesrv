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
    MumeSrv(const ISysfsReader &sysfsSwitch, ISysfsWriter &sysfsServoOpenPosNs, QObject* parent = 0);

  public slots:
    void setOpenPosition(double value);

  private:
    const ISysfsReader &sysfsSwitch;
    ISysfsWriter &sysfsServoOpenPosNs;

    bool isSwitchOn();

};

#endif // MUMESRV_HPP
