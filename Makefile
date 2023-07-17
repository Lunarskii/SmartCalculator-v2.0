VALGRIND_FLAGS				= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
APP_NAME					= SmartCalculator

all: install tests dvi dist lcov 

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
	rm -rf coverage*

dvi:
	open README.md

dist: install
	tar -czf $(APP_NAME).tar.gz --directory=build/ .

launch:
	./$(APP_NAME)

tests: install
	make -C build tests
	./build/tests

lcov: tests
	make -C build coverage
	cp build/coverage.info .
	genhtml coverage.info --output-directory coverage_report
	open coverage_report/index.html

clang:
	clang-format --style=google -i controller/*
	clang-format --style=google -i model/*
	clang-format --style=google -i view/*.cpp view/*.h
	clang-format --style=google -i structures.h type_predicates.h main.cpp
	clang-format --style=google -i tests/*

.PHONY: all install uninstall clean dvi dist launch tests clang valgrind lcov
