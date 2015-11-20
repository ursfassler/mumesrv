// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef PERSISTENCE_HPP
#define PERSISTENCE_HPP

#include "IPersistence.hpp"

#include <QString>
#include <QSettings>

class Persistence :
    public IPersistence
{
  public:
    Persistence();

    QString read(QString section, QString key) const override;
    void write(QString section, QString key, QString value) override;

  private:
    QSettings storage;
};

#endif // PERSISTENCE_HPP
