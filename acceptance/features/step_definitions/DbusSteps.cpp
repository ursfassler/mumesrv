// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "helper/Context.hpp"

#include <gtest/gtest.h>
#include <cucumber-cpp/defs.hpp>

#include <string>
#include <QVariant>

namespace
{
  WHEN("^I call the DBus method ([^\"]+) with the argument ((\\d+)(\\.(\\d+))?)$")
  {
    REGEX_PARAM(std::string, method);
    REGEX_PARAM(double, value);

    cucumber::ScenarioScope<Context> context;
    QMetaObject::invokeMethod(&context->mumeSrv, method.c_str(), Q_ARG(double, value));
  }


  THEN("^I expect the DBus property switchOn to read (true|false)$")
  {
    REGEX_PARAM(std::string, switchValueText);

    const auto expectedState = switchValueText == "true";

    cucumber::ScenarioScope<Context> context;
    const auto property = context->mumeSrv.property("switchOn");
    ASSERT_TRUE(property.isValid());
    ASSERT_EQ(expectedState, property.toBool());
  }

  THEN("^I expect the DBus property count to read (\\d+)$")
  {
    REGEX_PARAM(uint32_t, count);

    cucumber::ScenarioScope<Context> context;
    const auto property = context->mumeSrv.property("count");
    ASSERT_TRUE(property.isValid());
    ASSERT_EQ(count, property.toUInt());
  }

}
