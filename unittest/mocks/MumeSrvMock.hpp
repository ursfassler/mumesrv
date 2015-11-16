// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef MUMESRVMOCK_HPP
#define MUMESRVMOCK_HPP

#include <IMumeSrv.hpp>

#include <gmock/gmock.h>

class MumeSrvMock :
    public IMumeSrv
{
  public:
    MOCK_METHOD1(setOpenPosition, void(double value));
};

#endif // MUMESRVMOCK_H
