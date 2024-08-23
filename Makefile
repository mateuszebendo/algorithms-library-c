CC = gcc
CFLAGS = -Iinclude
SRC_DIR = src
TESTS_DIR = tests
BUILD_BIN = build/bin
BUILD_OBJ = build/obj

SRC_FILES = $(SRC_DIR)/algorithms.c
TESTS_FILES = $(TESTS_DIR)/test_algorithms.c

OBJ_SRC_FILES = $(BUILD_OBJ)/algorithms.o
OBJ_TESTS_FILES = $(BUILD_OBJ)/test_algorithms.o

EXECUTABLE = $(BUILD_BIN)/test_algorithms

all: $(EXECUTABLE)

$(BUILD_BIN):
	mkdir -p $(BUILD_BIN)

$(BUILD_OBJ):
	mkdir -p $(BUILD_OBJ)

$(EXECUTABLE): $(OBJ_SRC_FILES) $(OBJ_TESTS_FILES) | $(BUILD_BIN)
	$(CC) $(CFLAGS) $(OBJ_SRC_FILES) $(OBJ_TESTS_FILES) -o $@

$(OBJ_SRC_FILES): $(SRC_FILES) | $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $(SRC_FILES) -o $@

$(OBJ_TESTS_FILES): $(TESTS_FILES) | $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $(TESTS_FILES) -o $@

clean:
	rm -rf $(BUILD_OBJ) $(BUILD_BIN)
