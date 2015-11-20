# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

# language: en

Feature: Read switch information
  As a DBus client
  I want to read switch information
  In order to process it

Scenario Outline: I read the switch state and get the state according to the sysfs entry
  Given the sysfs file switch returns "<sysfs content>"

  Then I expect the DBus property switchOn to read <dbus value>

  Examples:
    | sysfs content | dbus value |
    | on            | true       |
    | off           | false      |

Scenario Outline: I read the counter and get  the state according to the sysfs entry
  Given the sysfs file count returns "<sysfs content>"

  Then I expect the DBus property count to read <dbus value>

  Examples:
    | sysfs content | dbus value |
    |             0 |          0 |
    |             1 |          1 |
    |         12912 |      12912 |
