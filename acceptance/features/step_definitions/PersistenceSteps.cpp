// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "helper/Context.hpp"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include <string>

namespace
{

  GIVEN("^there is a persistence entry \"servo\" \"([^\"]*)\" with the value \"([^\"]*)\"$")
  {
    REGEX_PARAM(std::string, key);
    REGEX_PARAM(std::string, value);

    cucumber::ScenarioScope<Context> context;
    context->persistence.write("servo", QString::fromStdString(key), QString::fromStdString(value));
  }

  THEN("^I expect a persistence entry \"servo\" \"([^\"]*)\" with the value \"([^\"]*)\"$")
  {
    REGEX_PARAM(std::string, key);
    REGEX_PARAM(std::string, value);

    cucumber::ScenarioScope<Context> context;
    ASSERT_EQ(value, context->persistence.read("servo", QString::fromStdString(key)).toStdString());
  }


}

