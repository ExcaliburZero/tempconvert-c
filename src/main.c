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

#include <stdio.h>

double get_stdin_temperature();
double farenheit_to_celcius(double farenheit_temp);

int main(void)
{
	// Get and print out the standard input
	double input = get_stdin_temperature();
	printf("F: %f\n", input);

	// Convert the temperature to Celcius and print it out
	double celcius_temp = farenheit_to_celcius(input);
	printf("C: %f\n", celcius_temp);
	
	// End the program successfully
	return 0;
}

/**
 * Returns the input temperature given in standard input.
 *
 * @returns The temperature given via standard input.
 */
double get_stdin_temperature()
{
	// Get the temperature from stdin
	double temperature;
	fscanf(stdin, "%lf", &temperature);
	
	// Return the temperature
	return temperature;
}

/**
 * Converts a Farenheit temperature to a Celcius temperature.
 *
 * @param farenheit_temp The temperature in Farenheit.
 * @returns The temperature in Celcius.
 */
double farenheit_to_celcius(double farenheit_temp)
{
	return (farenheit_temp - 32.0) * (5.0 / 9.0);
}
