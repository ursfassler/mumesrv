# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

# language: en

Feature: The servo end positions are persistent
  As a MUME user
  I want the device to have the correct end positions
  In order to use it without reconfiguration after boot

Scenario Outline: I start the service and the open position is written to the driver
  Given the sysfs file servo_open_pos_ns is writeable
  And there is a persistence entry "servo_open_pos_ns" with the value "<config value>"

  When I start the service

  Then I expect the content of the sysfs file servo_open_pos_ns to be <sysfs content>

  Examples:
    |  config value | sysfs content |
    |   0           |             0 |
    |   1           |    1000000000 |
    |   0.000000001 |             1 |
    |   0.000000123 |           123 |
    |   0.001       |       1000000 |

Scenario Outline: The servo open position is stored to persistence when written over the bus
  When I call the DBus method setOpenPosition with the argument <dbus value>

  Then I expect a persistence entry "servo_open_pos_ns" with the value "<config value>"

  Examples:
    |  dbus value  | config value |
    |  0           |  0.000000000 |
    |  1           |  1.000000000 |
    |  0.000000001 |  0.000000001 |
    |  0.000000123 |  0.000000123 |
    |  0.001       |  0.001000000 |
