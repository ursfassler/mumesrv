// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "helper/Context.hpp"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include <string>

namespace
{

  GIVEN("^there is a persistence entry \"servo_open_pos_ns\" with the value \"([^\"]*)\"$")
  {
    REGEX_PARAM(std::string, value);

    cucumber::ScenarioScope<Context> context;
    context->persistence.write("servo_open_pos_ns", QString::fromStdString(value));
  }

}

