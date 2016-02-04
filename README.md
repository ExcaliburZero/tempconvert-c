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

## Development
The following sections provide information on the develpoment of tempconvert-c.

### Compiling
The project can be compiled from source into an executable file throught he use of the project's makefile. That can be done by running the following command int he main directory of the project:

```
make compile
```

### Documentation
To generate the documentation of the application from its source code using Doxygen, run the following command within the main directory of the project. The documentation will then be generated in both HTML and LaTeX forms, and be placed in the `docs` sub-directory.

```
make docs
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

## License
tempconvert-c is availible under the [MIT License](http://opensource.org/licenses/MIT), see `LICENSE` for more information.
