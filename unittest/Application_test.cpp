// Copyright 2015 Urs Fässler, www.bitzgi.ch
// SPDX-License-Identifier:	GPL-3.0+

#include "mocks/PersistenceMock.hpp"
#include "mocks/MumeSrvMock.hpp"

#include <Application.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace
{
  class Application_Test :
      public testing::Test
  {
    public:
      void SetUp() override
      {
        ON_CALL(persistence, read(testing::_, testing::_))
            .WillByDefault(::testing::Return(QString{""}));
      }

      testing::NiceMock<PersistenceMock> persistence;
      MumeSrvMock mumeSrv;
      Application testee{persistence, mumeSrv};
  };

  TEST_F(Application_Test, load_servo_open_pos_from_persistence_on_init)
  {
    ON_CALL(persistence, read(QString{"servo"}, QString{"open_pos_ms"}))
        .WillByDefault(::testing::Return(QString{"0.012345"}));
    EXPECT_CALL(mumeSrv, setOpenPositionMs(0.012345)).Times(1);

    testee.init();
  }

  TEST_F(Application_Test, load_servo_close_pos_from_persistence_on_init)
  {
    ON_CALL(persistence, read(QString{"servo"}, QString{"close_pos_ms"}))
        .WillByDefault(::testing::Return(QString{"0.012345"}));
    EXPECT_CALL(mumeSrv, setClosePositionMs(0.012345)).Times(1);

    testee.init();
  }

  TEST_F(Application_Test, does_not_set_servo_open_pos_if_not_defined_in_persistence)
  {
    ON_CALL(persistence, read(QString{"servo"}, QString{"open_pos_ms"}))
        .WillByDefault(::testing::Return(QString{""}));
    EXPECT_CALL(mumeSrv, setOpenPositionMs(testing::_)).Times(0);

    testee.init();
  }

  TEST_F(Application_Test, write_double_to_persistence)
  {
    EXPECT_CALL(persistence, write(QString{"servo"}, QString{"open_pos_ms"}, QString{"1.000000"}));
    mumeSrv.openPositionMsChanged(1);
  }

}
