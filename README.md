# tempconvert-c
This is a small apllication written in C which converts temperatures.

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

## License
tempconvert-c is availible under the [MIT License](http://opensource.org/licenses/MIT), see `LICENSE` for more information.
