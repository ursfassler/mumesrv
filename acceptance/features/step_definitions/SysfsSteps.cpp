// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "helper/Context.hpp"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include <string>

namespace
{

  GIVEN("^the sysfs file switch returns \"([^\"]*)\"$")
  {
    REGEX_PARAM(std::string, sysfsContent);

    cucumber::ScenarioScope<Context> context;

    context->sysfsSwitch.content = QString::fromStdString(sysfsContent);
  }

  GIVEN("^the sysfs file count returns \"([^\"]*)\"$")
  {
    REGEX_PARAM(std::string, sysfsContent);

    cucumber::ScenarioScope<Context> context;

    context->sysfsCount.content = QString::fromStdString(sysfsContent);
  }

  GIVEN("^the sysfs file servo_open_pos_ns is writeable$")
  {
  }

  GIVEN("^the sysfs file servo_close_pos_ns is writeable$")
  {
  }

  THEN("^I expect the content of the sysfs file servo_open_pos_ns to be \"([^\"]*)\"$")
  {
    REGEX_PARAM(std::string, expected);

    cucumber::ScenarioScope<Context> context;
    ASSERT_EQ(expected, context->sysfsServoOpenPosNs.content.toStdString());
  }

  THEN("^I expect the content of the sysfs file servo_close_pos_ns to be \"([^\"]*)\"$")
  {
    REGEX_PARAM(std::string, expected);

    cucumber::ScenarioScope<Context> context;
    ASSERT_EQ(expected, context->sysfsServoClosePosNs.content.toStdString());
  }

}
