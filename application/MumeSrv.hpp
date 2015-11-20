// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef MUMESRV_HPP
#define MUMESRV_HPP

#include "ISysfs.hpp"
#include "IMumeSrv.hpp"

#include <QObject>

class MumeSrv :
    public IMumeSrv
{
    Q_OBJECT

    Q_PROPERTY(bool switchOn READ isSwitchOn())
    Q_PROPERTY(uint count READ count())

  public:
    MumeSrv(const ISysfsReader &sysfsSwitch, const ISysfsReader &sysfsCount, ISysfsWriter &sysfsServoOpenPosNs, QObject* parent = 0);

  public slots:
    void setOpenPositionMs(double value);

  private:
    const ISysfsReader &sysfsSwitch;
    const ISysfsReader &sysfsCount;
    ISysfsWriter &sysfsServoOpenPosNs;

    bool isSwitchOn();
    uint count();

};

#endif // MUMESRV_HPP
