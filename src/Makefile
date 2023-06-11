VALGRIND_FLAGS				= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
APP_NAME					= SmartCalculator

all: install

build:
	g++ -c model/*.cpp
	ar rc lib.a *.o
	ranlib lib.a
	rm -rf *.o
	g++ -c tests/*.cpp
	g++ *.o -o test_test lib.a -DGTEST_HAS_PTHREAD=1 -lgtest
	rm -rf *.o
	./test_test
	rm -rf test_test
	rm -rf lib.a

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
