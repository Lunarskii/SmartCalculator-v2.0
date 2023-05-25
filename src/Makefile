VALGRIND_FLAGS				= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
APP_NAME					= SmartCalculator

all: install

install:
	cmake -B build
	make -C build untitled
	cp build/untitled $(APP_NAME)

uninstall: clean
	rm -rf build
	rm -rf $(APP_NAME)
	rm -rf $(APP_NAME).tar.gz

clean:
	rm -rf valgrind.txt

dvi:
	open README.md

dist: install
	tar -czf $(APP_NAME).tar.gz --directory=build/ .

launch:
	./$(APP_NAME)

tests: install
	make -C build tests
	./build/tests

clang:
	clang-format --style=google -i controller/*
	clang-format --style=google -i model/*
	clang-format --style=google -i view/*view*

.PHONY: all install uninstall clean dvi dist launch tests clang valgrind
