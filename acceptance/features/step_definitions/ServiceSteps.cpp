// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "helper/Context.hpp"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>


namespace
{

  WHEN("^I start the service$")
  {
    cucumber::ScenarioScope<Context> context;
    context->application.init();
  }

}
