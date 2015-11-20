// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef PERSISTENCEDUMMY_H
#define PERSISTENCEDUMMY_H

#include <IPersistence.hpp>

#include <QString>
#include <QMap>

class PersistenceDummy :
    public IPersistence
{
  public:
    PersistenceDummy();

    void write(QString section, QString key, QString value) override;
    QString read(QString section, QString key) const override;

  private:
    QMap<QString,QMap<QString,QString>> values;

};

#endif // PERSISTENCEDUMMY_H
