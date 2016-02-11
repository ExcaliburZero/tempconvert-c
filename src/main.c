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
#include <stdlib.h>
#include <unistd.h>

#include "temperature_units.h"

double get_stdin_temperature();

/**
 * Performs the various actions of the program. It is run when the program is executed.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The arguements passed to the program.
 * @returns The end code of the program.
 */
int main(int argc, char* argv[])
{
	double input;
	
	// Check if the command contains the input temperature or not
	int units_from_args;
	char * p;
	char * last_arguement = argv[argc - 1];
	strtod(last_arguement, &p);

	// Get the input temperature from the command or standard input
	if (*p == '\0')
	{
		// Input from command
		input = atof(last_arguement);
		units_from_args = 1;
	}
	else
	{
		// Input from standard input
		input = get_stdin_temperature();
		units_from_args = 0;
	}

	// Make sure that there are sufficient command arguments
	if (argc - units_from_args < 3)
	{
		// End program with error
		fprintf(stderr, "Incorrect number of command arguements.\nYou may have forgotten to include the temperature units in the command.\n");
		return 1;
	}
	
	// Get the temperature units from the comamnd arguements
	char start_unit = *argv[argc - units_from_args - 2];
	char end_unit = *argv[argc - units_from_args - 1];

	// Make sure that the temperature units are valid
	char entered_flags[2] = {start_unit, end_unit};
	int valid_flags = 1;

	for (int i = 0; i < 2; i++)
	{
		switch (entered_flags[i])
		{
			case 'c':
			case 'f':
			case 'k':
				break;
			default:
				printf("Invalid temperature unit: %c\n", entered_flags[i]);
				valid_flags = 0;
		}
	}

	// Make sure that two temperature flags have been entered
	if(valid_flags == 0)
	{
		// End program with error
		fprintf(stderr, "Incorrect number of temperature flags.\n");
		return 1;
	}

	// Convert the start unit into Celsius
	double celsius_temp;
	switch(start_unit)
	{
		case 'c':
			celsius_temp = input;
			break;
		case 'f':
			celsius_temp = farenheit_to_celsius(input);
			break;
		case 'k':
			celsius_temp = kelvin_to_celsius(input);
			break;
	}

	// Convert from Celsius to the end unit
	double output;
	switch(end_unit)
	{
		case 'c':
			output = celsius_temp;
			break;
		case 'f':
			output = celsius_to_farenheit(celsius_temp);
			break;
		case 'k':
			output = celsius_to_kelvin(celsius_temp);
			break;
	}

	// Print out the resulting temperature
	printf("%lf\n", output);
	
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
