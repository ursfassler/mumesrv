// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "helper/Context.hpp"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include <string>

namespace
{

  GIVEN("^the sysfs file switch returns (on|off)$")
  {
    REGEX_PARAM(std::string, sysfsContent);

    cucumber::ScenarioScope<Context> context;

    context->sysfsSwitch.read_return = sysfsContent;
  }

}
