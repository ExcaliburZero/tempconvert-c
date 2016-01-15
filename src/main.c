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

void get_standard_input(char * input);

int main(void)
{
	// Get and print out the standard input
	char * input;
	get_standard_input(input);
	puts(input);
	
	// End the program successfully
	return 0;
}

void get_standard_input(char * input)
{
	// Get the length of the standard input
	int stdinLength;
	fseek(stdin, 0L, SEEK_END);
	stdinLength = ftell(stdin);
	fseek(stdin, 0L, SEEK_SET);

	// Store the standard input into a character array
	char input_stream[stdinLength];
	fgets(input_stream, stdinLength, stdin);

	// Return the input
	input = input_stream;
}
