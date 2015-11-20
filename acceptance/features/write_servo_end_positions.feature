# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

# language: en

Feature: Write servo end positions
  As a DBus client
  I want to write the servo end positions
  In order to calibrate the machine

Scenario Outline: I write the servo open position and see the value written into the sysfs file
  Given the sysfs file servo_open_pos_ns is writeable

  When I call the DBus method setOpenPositionMs with the argument <dbus value>

  Then I expect the content of the sysfs file servo_open_pos_ns to be "<sysfs content>"

  Examples:
    |  dbus value  | sysfs content |
    |    0         |             0 |
    |    1         |       1000000 |
    | 1000         |    1000000000 |
    |    0.000001  |             1 |
    |    0.000123  |           123 |
