help:
		@echo "The following make commands are valid, and can be run as 'make COMMAND':"
		@echo ""
		@echo "  compile  compiles the application" 
		@echo "  docs     generates the application's documentation"
		@echo "  man      displays the man file for the application"
		@echo ""

compile:
	gcc -o tempconvert src/main.c -Wall -Werror -std=gnu99

docs:
	doxygen

man:
	man ./tempconvert.1
