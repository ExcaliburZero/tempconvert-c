help:
		@echo "The following make commands are valid, and can be run as 'make COMMAND':"
		@echo ""
		@echo "  compile  compiles the application" 
		@echo "  docs     generates the application's documentation"
		@echo ""

compile:
	gcc -o tempconvert src/main.c -Wall -Werror

docs:
	doxygen
