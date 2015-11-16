// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "IPersistence.hpp"
#include "IMumeSrv.hpp"

class Application
{
  public:
    Application(IPersistence &persistence, IMumeSrv &mumeSrv);

    void init();

  private:
    IPersistence &persistence;
    IMumeSrv &mumeSrv;
};

#endif // APPLICATION_HPP
