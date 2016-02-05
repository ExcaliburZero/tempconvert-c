/*
 * BEGIN LICENSE
 * Copyright (C) 2016 Christopher Wells <cwellsny@nycap.rr.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * END LICENSE
 */

#include "temperature_units.h"

/**
 * Converts a Farenheit temperature to a Celsius temperature.
 *
 * @param farenheit_temp The temperature in Farenheit.
 * @returns The temperature in Celsius.
 */
double farenheit_to_celsius(double farenheit_temp)
{
	return (farenheit_temp - 32.0) * (5.0 / 9.0);
}

/**
 * Converts a Celsius temperature to a Farenheit temperature.
 *
 * @param celsius_temp The temperature in Celsius.
 * @returns The temperature in Farenheit.
 */
double celsius_to_farenheit(double celsius_temp)
{
	return celsius_temp * (9.0 / 5.0) + 32.0;
}

/**
 * Converts a Kelvin temperature to a Celsius temperature.
 *
 * @param kelvin_temp The temperature in Kelvin.
 * @returns The temperature in Celsius.
 */
double kelvin_to_celsius(double kelvin_temp)
{
	return kelvin_temp - 273.15;
}

/**
 * Converts a Celsius temperature to a kelvin temperature.
 *
 * @param celsius_temp The temperature in Celsius.
 * @returns The temperature in Kelvin.
 */
double celsius_to_kelvin(double celsius_temp)
{
	return celsius_temp + 273.15;
}
