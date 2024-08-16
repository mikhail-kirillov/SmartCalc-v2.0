
OS_NAME=$(shell uname)
CPP_COMPILER=g++
CPP_COMPILER_FLAGS=-Wall -Wextra -Werror -pedantic -std=c++17
TESTS_FLAGS=-lgtest -lpthread
TEST_C_FILES = $(shell find tests -name "*.cc")
CONTROLLER_C_FILES = $(shell find src/controller -name "*.cc")
MODEL_C_FILES = $(shell find src/model -name "*.cc")
BUILD_DIR=build
DIST_NAME=SmartCalc.tar.gz
TEST_DIR=tests
TEST_NAME=tests
SRC_DIR=src
README_FILE=README.md
MAKEFILE=Makefile
CMAKEFILE=CMakeLists.txt


ifeq ($(OS_NAME), Darwin)
	OPEN_CMD = open
	APP_NAME = SmartCalc.app
	OPEN_APP = $(OPEN_CMD) $(APP_NAME)
else
	FLAGS += -lm -lrt
	OPEN_CMD = xdg-open
	APP_NAME = SmartCalc
	OPEN_APP = ./$(APP_NAME)
endif

.PHONY: all install uninstall clean dvi dist tests open

all: uninstall clean dist install open tests dvi

install: uninstall clean
	mkdir $(BUILD_DIR) && cd $(BUILD_DIR) && cmake .. && make
	mv $(BUILD_DIR)/$(APP_NAME) .

uninstall:
	rm -rf $(APP_NAME) 2> /dev/null

clean:
	rm -rf $(BUILD_DIR) $(DIST_NAME) $(TEST_DIR)/$(TEST_NAME) 2> /dev/null

dvi: $(README_FILE)
	$(OPEN_CMD) $(README_FILE)

dist: clean $(SRC_DIR) $(TEST_DIR)/*.cc $(TEST_DIR)/*.h $(README_FILE) $(CMAKEFILE) $(MAKEFILE)
	tar -czf $(DIST_NAME) $(SRC_DIR) $(TEST_DIR)/*.cc $(TEST_DIR)/*.h $(README_FILE) $(CMAKEFILE) $(MAKEFILE)

tests: clean
	$(CPP_COMPILER) $(CPP_COMPILER_FLAGS) -o $(TEST_DIR)/$(TEST_NAME) $(TEST_C_FILES) $(CONTROLLER_C_FILES) $(MODEL_C_FILES) $(TESTS_FLAGS)
	./$(TEST_DIR)/$(TEST_NAME)

open: $(APP_NAME)
	$(OPEN_APP)


.SILENT: all install uninstall clean dvi dist tests open
