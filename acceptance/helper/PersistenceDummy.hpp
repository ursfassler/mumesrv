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

    void write(QString key, QString value);
    QString read(QString key) const override;

  private:
    QMap<QString,QString> values;

};

#endif // PERSISTENCEDUMMY_H
