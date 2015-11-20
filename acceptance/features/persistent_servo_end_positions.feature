# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

# language: en

Feature: The servo end positions are persistent
  As a MUME user
  I want the device to have the correct end positions
  In order to use it without reconfiguration after boot

Scenario Outline: I start the service and the open position is written to the driver
  Given the sysfs file servo_open_pos_ns is writeable
  And there is a persistence entry "servo" "open_pos_ms" with the value "<config value>"

  When I start the service

  Then I expect the content of the sysfs file servo_open_pos_ns to be "<sysfs content>"

  Examples:
    |  config value | sysfs content |
    |    0          |             0 |
    |    1          |       1000000 |
    | 1000          |    1000000000 |
    |    0.000001   |             1 |
    |    0.000123   |           123 |

Scenario Outline: The servo open position is stored to persistence when written over the bus
  When I call the DBus method setOpenPositionMs with the argument <dbus value>

  Then I expect a persistence entry "servo" "open_pos_ms" with the value "<config value>"

  Examples:
    |  dbus value  | config value |
    |    0         |    0.000000  |
    | 1000         | 1000.000000  |
    |    0.000001  |    0.000001  |
    |    0.000123  |    0.000123  |
    |    1         |    1.000000  |

Scenario Outline: I start the service and the close position is written to the driver
  Given the sysfs file servo_close_pos_ns is writeable
  And there is a persistence entry "servo" "close_pos_ms" with the value "<config value>"

  When I start the service

  Then I expect the content of the sysfs file servo_close_pos_ns to be "<sysfs content>"

  Examples:
    |  config value | sysfs content |
    |    0          |             0 |
    |    1          |       1000000 |
    | 1000          |    1000000000 |
    |    0.000001   |             1 |
    |    0.000123   |           123 |

Scenario Outline: The servo close position is stored to persistence when written over the bus
  When I call the DBus method setClosePositionMs with the argument <dbus value>

  Then I expect a persistence entry "servo" "close_pos_ms" with the value "<config value>"

  Examples:
    |  dbus value  | config value |
    |    0         |    0.000000  |
    | 1000         | 1000.000000  |
    |    0.000001  |    0.000001  |
    |    0.000123  |    0.000123  |
    |    1         |    1.000000  |

