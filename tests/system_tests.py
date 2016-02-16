#!/bin/python
### BEGIN LICENSE
# The MIT License (MIT)
#
# Copyright (C) 2016 Christopher Wells <cwellsny@nycap.rr.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
### END LICENSE
"""These are system tests for tempconvert-c."""

from __future__ import print_function
from subprocess import Popen, PIPE
import sys


def run_test(input_temp, input_unit, output_unit, expected_temp):
    """
    Runs a test of the program with the given conditions, and compare it
    against the given expected output.

    :param float input_temp: The input temperature.
    :param str input_unit: The input unit.
    :param str output_unit: The output unit.
    :param float expected_temp: The temperature output expected.
    :returns bool: Whether or not the program output was correct.
    """
    # Construct the command to run
    command = "echo '" + str(input_temp) + "' | ./tempconvert " + input_unit + " " + output_unit

    # Run the command and get its output
    program_run = Popen(command, shell=True, stdout=PIPE)
    try:
        output = float(program_run.communicate()[0])
    except ValueError:
        return False

    # Return if the output was correct or not
    return output == expected_temp


def test_error(command, expected_error_message):
    """
    Runs a given invalid command and makes sure that the correct error message
    is given for that command.

    :param str command: The invalid command to run.
    :param str expected_error_message: The error message expected for the
    command.
    :returns bool: Whether or not the error message was correct.
    """
    # Run the command and get its output
    program_run = Popen(command, shell=True, stderr=PIPE)
    output = program_run.communicate()[1]
    if output is not None:
        output = output.decode("utf-8")

    # Return if the error message was correct or not
    return expected_error_message == output


def main():
    """
    Runs the various system tests.

    If all tests pass, then the script ends successfully. If any tests fail,
    then the failing cases are printed out, and the script ends with an error.
    """
    # Setup the test cases
    test_cases = [
        [32.0, "f", "c", 0.0],
        [122, "f", "c", 50],
        [32.0, "f", "k", 273.15],
        [273.15, "k", "c", 0.0],
        [0.0, "c", "c", 0.0],
    ]

    # Run each of the test cases and log them if they fail
    failures = 0
    failure_output = ""
    for test_case in test_cases:
        if not run_test(test_case[0], test_case[1], test_case[2], test_case[3]):
            failures += 1
            failure_output += "---------------------\n"
            failure_output += "Test Failed:\n"
            failure_output += str(test_case) + "\n"

    # Test invalid command runs
    invalid_command_cases = [
        ["echo 'fgh' | ./tempconvert f c", "Invalid input temperature: fgh\n"],
        ["./tempconvert", "Incorrect number of command arguements: 0\nYou may have forgotten to include the temperature units in the command.\n"],
        ["./tempconvert f", "Incorrect number of command arguements: 1\nYou may have forgotten to include the temperature units in the command.\n"],
        ["./tempconvert z c 0", "Invalid temperature unit: z\nIncorrect number of temperature flags.\n"],
        ["./tempconvert z g 0", "Invalid temperature unit: z\nInvalid temperature unit: g\nIncorrect number of temperature flags.\n"],
    ]

    # Run each of the invalid command cases to make sure that they return the
    # correct error messages
    for invalid_command_case in invalid_command_cases:
        if not test_error(invalid_command_case[0], invalid_command_case[1]):
            failures += 1
            failure_output += "---------------------\n"
            failure_output += "Test Failed:\n"
            failure_output += str(invalid_command_case) + "\n"

    # If there were any failures, then print them out into stderr and end the
    # script
    if failures > 0:
        output_messages = "---------------------\n"
        output_messages += str(failures) + " tests failed.\n"
        output_messages += failure_output
        output_messages += "---------------------\n"
        output_messages = output_messages[:-2]

        print(output_messages, file=sys.stderr)
        sys.exit(1)

    # If there weren't any errors, then end the script
    return 0

# Run the main method
if __name__ == '__main__':
    main()
