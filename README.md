# tempconvert-c [![Travis CI Status](https://api.travis-ci.org/ExcaliburZero/tempconvert-c.svg)](https://travis-ci.org/ExcaliburZero/tempconvert-c)
This is a small apllication written in C which converts temperatures.

## Usage
Once tempconvert-c has been compiled or installed, you can run it as follows. The temperature to be converted should be given in through standard input. The input and output temperatures can be specified through flags, with the input temperature flag coming before the output temperature flag.

```
$ echo "32" | tempconvert -f -c
0.000000
```

### Temperature flags
| Flag | Temperature Unit | Abbreviation |
|------|------------------|--------------|
| -c   | Celsius          | °C           |
| -f   | Farenheit        | °F           |
| -k   | Kelvin           | K            |

## Development
The following sections provide information on the develpoment of tempconvert-c.

### Compiling
The project can be compiled from source into an executable file throught he use of the project's makefile. That can be done by running the following command in the main directory of the project:

```
make compile
```

### Integration tests
The project has a set of integration tests associated with it which can be run after the program has been compiled in order to make usre that the compiled program correctly functions with certain test inputs and outputs. The tests can be run by using the following command within the main directory of the project:

```
make intetest
```

The integration tests are handled by the file `tests/integration_tests.py`. Test cases are defined using a list which gives the input, input unit, output unit, and expected output. If any of the given tests fail then error messages are printed out for each failure.

```
[Input_Temp, "Input_Unit", "Output_Unit", Expected_Output],

[32.0, "f", "c", 0.0],
```

### Documentation
To generate the documentation of the application from its source code using Doxygen, run the following command within the main directory of the project. The documentation will then be generated in both HTML and LaTeX forms, and be placed in the `docs` sub-directory.

```
make doc
```

The documentation generation is handled by defualt using the project's makefile, however you can also generate it by running the `doxygen` command with any flags that you want to use.

```
doxygen
```

### Manual
The manual page for the application can be viewed from source by running the following command:

```
make man
```

### Adding Units
Temperature units are handled in a few different places throughout the program and its documentation. The actual temperature conversion works by first converting the input temperature into Celsius, and then converting the Celsius temperature into the output temperature. Thus, to add a new unit, only functions to convert the temperature into and from Celsius need to be added. The temperature conversion functions can be found in the `src/temperature_units.c` and `src/temperature_units.h` source files.

```
double farenheit_to_celsius(double farenheit_temp);
double celsius_to_farenheit(double celsius_temp);
```

In addition to adding the new functions, the new unit also needs to be added to the arguement parser and unit conversion handlers that are within the `src/main.c` file.

The readme file (`README.md`) and manual file (`tempconvert.1`) should both also be updated to include information on the new unit.

## License
The source code of tempconvert-c is availible under the [MIT License](http://opensource.org/licenses/MIT), see `LICENSE` for more information.

The manual file for the program in availible under the [GNU Free Documentation License version 1.3](https://www.gnu.org/licenses/fdl-1.3-standalone.html).
