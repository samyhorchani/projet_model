CC = gcc
CFLAGS = -Wall -O3 -g

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
BENCHMARK_DIR = benchmark

# Find all .c files in SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Create a list of object files in BUILD_DIR, excluding main.o
OBJS = $(filter-out $(BUILD_DIR)/main.o, $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS)))

# Executable names
MAIN_EXEC = main
BENCHMARK_EXEC = benchmarks

# Benchmark source and object files
BENCHMARK_SRC = $(BENCHMARK_DIR)/benchmarks.c
BENCHMARK_OBJ = $(patsubst $(BENCHMARK_DIR)/%.c, $(BUILD_DIR)/%.o, $(BENCHMARK_SRC))

# Dependencies
DEPS = $(wildcard $(INCLUDE_DIR)/*.h)

# Default target
all: $(MAIN_EXEC) $(BENCHMARK_EXEC)

# Main executable
$(MAIN_EXEC): $(BUILD_DIR)/main.o $(filter-out $(BENCHMARK_OBJ), $(OBJS))
	$(CC) $(CFLAGS) $^ -o $@ -lm

# Benchmark executable
$(BENCHMARK_EXEC): $(BENCHMARK_OBJ) $(filter-out $(BUILD_DIR)/main.o, $(OBJS))
	$(CC) $(CFLAGS) $^ -o $@ -lm

# Generic rule for building object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Rule for building benchmark object file
$(BENCHMARK_OBJ): $(BENCHMARK_SRC) $(DEPS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR)/*.o $(MAIN_EXEC) $(BENCHMARK_EXEC)

.PHONY: all clean
