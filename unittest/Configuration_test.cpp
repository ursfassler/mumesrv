// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include <Configuration.hpp>

#include <gtest/gtest.h>
#include <QStringList>
#include <QCoreApplication>

namespace
{
  static char *argv[]{""};


  class Configuration_Test :
      public ::testing::Test
  {
    public:

      int argc = 1;
      QCoreApplication app{argc, argv};
  };


  TEST_F(Configuration_Test, use_system_dbus_by_default)
  {
    QStringList arg{"", ""};
    Configuration testee{arg};

    ASSERT_TRUE(testee.useSystemDbus());
  }

  TEST_F(Configuration_Test, use_session_dbus_when_specified)
  {
    QStringList arg{"", "--session-dbus", ""};
    Configuration testee{arg};

    ASSERT_FALSE(testee.useSystemDbus());
  }

  TEST_F(Configuration_Test, specify_sysfs_directory_as_command_line_argument)
  {
    QStringList arg{"", "/sys/bus/platform/devices/mume/"};
    Configuration testee{arg};

    ASSERT_EQ("/sys/bus/platform/devices/mume/", testee.sysfsRoot());
  }

  TEST_F(Configuration_Test, no_positional_argument_is_invalid)
  {
    QStringList arg{""};
    Configuration testee{arg};

    ASSERT_FALSE(testee.isValid());
  }

  TEST_F(Configuration_Test, more_than_one_positional_arguments_are_invalid)
  {
    QStringList arg{"", "", ""};
    Configuration testee{arg};

    ASSERT_FALSE(testee.isValid());
  }

  TEST_F(Configuration_Test, help_text_mentiones_position_arguments)
  {
    QStringList arg{""};
    Configuration testee{arg};

    ASSERT_TRUE(testee.helpText().contains("sysfs-root"));
  }

}

