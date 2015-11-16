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
    MOCK_CONST_METHOD1(read, QString(QString));
};

#endif // PERSISTENCEMOCK_H
