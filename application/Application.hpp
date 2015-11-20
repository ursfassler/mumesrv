// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "IPersistence.hpp"
#include "IMumeSrv.hpp"

#include <QObject>
#include <functional>

class Application :
    public QObject
{
    Q_OBJECT

  public:
    Application(IPersistence &persistence, IMumeSrv &mumeSrv);

    void init();

  private slots:
    void setOpenPositionMs(double value);
    void setClosePositionMs(double value);

  private:
    IPersistence &persistence;
    IMumeSrv &mumeSrv;
    void loadValue(QString key, std::function<void(IMumeSrv &, double)> writer);
};

#endif // APPLICATION_HPP
