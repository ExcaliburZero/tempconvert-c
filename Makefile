help:
		@echo "The following make commands are valid, and can be run as 'make COMMAND':"
		@echo ""
		@echo "  compile  compiles the application" 
		@echo "  intetest runs the integration tests"
		@echo "  doc      generates the application's documentation"
		@echo "  man      displays the man file for the application"
		@echo ""

compile:
	gcc -o tempconvert src/main.c src/temperature_units.c -Wall -Werror -std=gnu99

intetest:
	python tests/integration_tests.py

doc:
	doxygen

man:
	man ./tempconvert.1
