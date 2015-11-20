// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef PERSISTENCEMOCK_H
#define PERSISTENCEMOCK_H

#include <IPersistence.hpp>

#include <gmock/gmock.h>

class PersistenceMock :
    public IPersistence
{
  public:
    MOCK_CONST_METHOD2(read, QString(QString,QString));
    MOCK_METHOD3(write, void(QString,QString,QString));
};

#endif // PERSISTENCEMOCK_H
