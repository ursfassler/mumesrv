// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#ifndef IMUMESRV_HPP
#define IMUMESRV_HPP

class IMumeSrv
{
  public:
    virtual ~IMumeSrv() = default;

    virtual void setOpenPosition(double value) = 0;
};

#endif // IMUMESRV_H
