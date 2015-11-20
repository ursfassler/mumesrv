// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "mocks/SysfsReaderMock.hpp"
#include "mocks/SysfsWriterMock.hpp"

#include <MumeSrv.hpp>

#include <gtest/gtest.h>

#include <QVariant>
#include <QSignalSpy>

namespace
{

  class MumeSrv_Test :
      public testing::Test
  {
    public:
      const testing::NiceMock<SysfsReaderMock> sysfsSwitch;
      SysfsWriterMock sysfsServoOpenPosNs;
      MumeSrv testee{sysfsSwitch, sysfsServoOpenPosNs};
  };

  TEST_F(MumeSrv_Test, has_boolean_switchOn_property)
  {
    ON_CALL(sysfsSwitch, read()).WillByDefault(::testing::Return(QString("")));

    const auto property = testee.property("switchOn");
    ASSERT_TRUE(property.isValid());
    ASSERT_EQ(QVariant::Bool, property.type());
  }

  TEST_F(MumeSrv_Test, read_switchOn_property)
  {
    EXPECT_CALL(sysfsSwitch, read()).WillOnce(::testing::Return(QString("on")));
    ASSERT_EQ(true, testee.property("switchOn").toBool());

    EXPECT_CALL(sysfsSwitch, read()).WillOnce(::testing::Return(QString("off")));
    ASSERT_EQ(false, testee.property("switchOn").toBool());
  }

  TEST_F(MumeSrv_Test, write_0_via_setOpenPositionMs_to_sysfs)
  {
    EXPECT_CALL(sysfsServoOpenPosNs, write(QString("0"))).Times(1);
    QMetaObject::invokeMethod(&testee, "setOpenPositionMs", Q_ARG(double, 0));
  }

  TEST_F(MumeSrv_Test, write_1000_via_setOpenPositionMs_to_sysfs)
  {
    EXPECT_CALL(sysfsServoOpenPosNs, write(QString("1000000000"))).Times(1);
    QMetaObject::invokeMethod(&testee, "setOpenPositionMs", Q_ARG(double, 1000));
  }

  TEST_F(MumeSrv_Test, write_0_1_via_setOpenPositionMs_to_sysfs)
  {
    EXPECT_CALL(sysfsServoOpenPosNs, write(QString("100000"))).Times(1);
    QMetaObject::invokeMethod(&testee, "setOpenPositionMs", Q_ARG(double, 0.1));
  }

  TEST_F(MumeSrv_Test, write_3_456_via_setOpenPositionMs_to_sysfs)
  {
    EXPECT_CALL(sysfsServoOpenPosNs, write(QString("3456000"))).Times(1);
    QMetaObject::invokeMethod(&testee, "setOpenPositionMs", Q_ARG(double, 3.456));
  }

  TEST_F(MumeSrv_Test, write_setOpenPositionMs_sends_signal)
  {
    EXPECT_CALL(sysfsServoOpenPosNs, write(testing::_));
    QSignalSpy spy{&testee, SIGNAL(openPositionMsChanged(double))};

    QMetaObject::invokeMethod(&testee, "setOpenPositionMs", Q_ARG(double, 3.456));

    ASSERT_EQ(1, spy.count());
    const auto args = spy[0];
    ASSERT_EQ(1, args.count());
    ASSERT_DOUBLE_EQ(3.456, args[0].toDouble());
  }
}

