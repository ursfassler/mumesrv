// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "mocks/SysfsReaderMock.hpp"

#include <MumeSrv.hpp>

#include <gtest/gtest.h>

#include <QVariant>

namespace
{

  TEST(MumeSrv_Test, has_boolean_switchOn_property)
  {
    const ::testing::NiceMock<SysfsReaderMock> sysfsSwitch;
    const MumeSrv testee{sysfsSwitch};

    ON_CALL(sysfsSwitch, read()).WillByDefault(::testing::Return(QString("")));

    const auto property = testee.property("switchOn");
    ASSERT_TRUE(property.isValid());
    ASSERT_EQ(QVariant::Bool, property.type());
  }

  TEST(MumeSrv_Test, read_switchOn_property)
  {
    const SysfsReaderMock sysfsSwitch;
    const MumeSrv testee{sysfsSwitch};

    EXPECT_CALL(sysfsSwitch, read()).WillOnce(::testing::Return(QString("on")));
    ASSERT_EQ(true, testee.property("switchOn").toBool());

    EXPECT_CALL(sysfsSwitch, read()).WillOnce(::testing::Return(QString("off")));
    ASSERT_EQ(false, testee.property("switchOn").toBool());
  }

}

