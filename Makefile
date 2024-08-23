# Definições de variáveis
CC = gcc
CFLAGS = -Iinclude -Itests/Unity/src -Wall -Wextra
LDFLAGS =
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
UNITY_DIR = $(TEST_DIR)/Unity/src
BUILD_OBJ = build/obj
BUILD_BIN = build/bin

# Arquivos de origem e objetos
SRC_FILES = $(SRC_DIR)/mathlib.c
OBJ_FILES = $(BUILD_OBJ)/mathlib.o

TEST_SRC_FILES = $(TEST_DIR)/test_mathlib.c $(UNITY_DIR)/unity.c
TEST_OBJ_FILES = $(BUILD_OBJ)/test_mathlib.o $(BUILD_OBJ)/unity.o

# Nome do executável
TARGET = $(BUILD_BIN)/test_mathlib

# Regra principal para construir o executável
all: $(TARGET)

# Regra para garantir a criação dos diretórios
$(BUILD_OBJ):
	mkdir -p $(BUILD_OBJ)

$(BUILD_BIN):
	mkdir -p $(BUILD_BIN)

# Regra para construir o executável
$(TARGET): $(BUILD_OBJ) $(OBJ_FILES) $(TEST_OBJ_FILES) $(BUILD_BIN)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(TEST_OBJ_FILES) -o $@

# Regra para compilar arquivos de origem para objetos
$(BUILD_OBJ)/mathlib.o: $(SRC_FILES) | $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mathlib.c -o $@

$(BUILD_OBJ)/test_mathlib.o: $(TEST_DIR)/test_mathlib.c | $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $(TEST_DIR)/test_mathlib.c -o $@

$(BUILD_OBJ)/unity.o: $(UNITY_DIR)/unity.c | $(BUILD_OBJ)
	$(CC) $(CFLAGS) -c $(UNITY_DIR)/unity.c -o $@

# Limpeza dos arquivos compilados
clean:
	rm -rf $(BUILD_OBJ) $(BUILD_BIN)

.PHONY: all clean
