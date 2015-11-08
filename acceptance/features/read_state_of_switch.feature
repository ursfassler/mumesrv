# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

# language: en

Feature: Read state of switch
  As a DBus client
  I want to read the state of the switch
  In order to process it

Scenario Outline: I read the switch and get the state according to the sysfs entry
  Given the sysfs file switch returns <sysfs content>

  Then I expect the DBus property switchOn to read <dbus value>

  Examples:
    | sysfs content | dbus value |
    | on            | true       |
    | off           | false      |
