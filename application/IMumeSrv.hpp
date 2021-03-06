// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef IMUMESRV_HPP
#define IMUMESRV_HPP

#include <QObject>

class IMumeSrv :
    public QObject
{
    Q_OBJECT

  public:
    IMumeSrv(QObject *parent = nullptr);
    virtual ~IMumeSrv();

    virtual void setOpenPositionMs(double value) = 0;
    virtual void setClosePositionMs(double value) = 0;

  signals:
    void openPositionMsChanged(double value);
    void closePositionMsChanged(double value);
};

#endif // IMUMESRV_H
