vpath %.cpp tests
vpath %.cpp Backend
vpath %.cpp GUI

CC							= g++
CFLAGS						= -Wall -Werror -Wextra -std=c++17 -pedantic -g
LDFLAGS						= $(shell pkg-config --cflags --libs gtest)
GCOV_FLAGS					= -fprofile-arcs -ftest-coverage -fPIC
VALGRIND_FLAGS				= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med

SRC_BACKEND_DIR				= Backend/
SRC_GUI_DIR					= GUI/
SRC_TESTS_DIR				= tests/
OBJ_BACKEND_DIR				= ../obj/backend/
OBJ_GUI_DIR					= ../obj/gui/
OBJ_TESTS_DIR				= ../obj/tests/


BACKEND_LIBRARY				= smartcalculator.a
BUILD_FOLDERS				:= $(shell mkdir -p $(OBJ_BACKEND_DIR); mkdir -p $(OBJ_GUI_DIR); mkdir -p $(OBJ_TESTS_DIR))
SRC_BACKEND					:= $(wildcard $(SRC_BACKEND_DIR)*.cpp)
SRC_TESTS					:= $(wildcard $(SRC_TESTS_DIR)*.cpp)
OBJ_BACKEND					:= $(patsubst %.cpp, $(OBJ_BACKEND_DIR)%.o, $(notdir $(SRC_BACKEND)))
OBJ_TESTS					:= $(patsubst %.cpp, $(OBJ_TESTS_DIR)%.o, $(notdir $(SRC_TESTS)))

all: $(BACKEND_LIBRARY) test clean

$(BACKEND_LIBRARY): $(OBJ_BACKEND)
	ar rc $(BACKEND_LIBRARY) $(OBJ_BACKEND)
	ranlib $(BACKEND_LIBRARY)

test: $(BACKEND_LIBRARY) $(OBJ_TESTS)
	$(CC) $(CFLAGS) $(OBJ_TESTS) -o test $(BACKEND_LIBRARY) $(LDFLAGS)
	./test --gtest_color=yes --gtest_brief=1

# gcov_report: $(OBJ_TEST)
# 	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(LDFLAGS)
# 	./test
# 	lcov -t "test" -o gcov.info -c -d .
# 	genhtml -o report gcov.info
# 	rm -rf ./*.gc*

$(OBJ_BACKEND_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_TESTS_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ../obj/
	rm -rf test
	rm -rf *.a
	rm -rf report
	rm -rf *.info
	rm -rf valgrind.txt

open: 
	open report/index.html

valgrind: test
	valgrind $(VALGRIND_FLAGS) ./test
	! grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"

clang:
	clang-format --style=google -i $(SRC_PROJECT_DIR)*
	clang-format --style=google -i $(SRC_TEST_DIR)*

.PHONY: all clean rebuild open clang valgrind docker
