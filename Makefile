# Samy HORCHANI (n° étudiant : 28706765)
CC = gcc
CFLAGS = -Wall -O3 -g

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
BENCHMARK_DIR = benchmark

# Trouver tous les fichiers .c files dans SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Creation d'une liste de fichiers d'objets à l'exception de main.o
OBJS = $(filter-out $(BUILD_DIR)/main.o, $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS)))

# Noms des executables
MAIN_EXEC = main
BENCHMARK_EXEC = benchmarks

# source Benchmark et fichiers objets
BENCHMARK_SRC = $(BENCHMARK_DIR)/benchmarks.c
BENCHMARK_OBJ = $(patsubst $(BENCHMARK_DIR)/%.c, $(BUILD_DIR)/%.o, $(BENCHMARK_SRC))

# Dépendances
DEPS = $(wildcard $(INCLUDE_DIR)/*.h)

# Cibles par défaut
all: $(MAIN_EXEC) $(BENCHMARK_EXEC)

# Vérification de l'existence du répertoire build et création si nécessaire
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Génération de l'executable main
$(MAIN_EXEC): $(BUILD_DIR) $(BUILD_DIR)/main.o $(filter-out $(BENCHMARK_OBJ), $(OBJS))
	$(CC) $(CFLAGS) $(BUILD_DIR)/main.o $(filter-out $(BENCHMARK_OBJ), $(OBJS)) -o $@ -lm

# Génération de l'executable benchmark
$(BENCHMARK_EXEC): $(BUILD_DIR) $(BENCHMARK_OBJ) $(filter-out $(BUILD_DIR)/main.o, $(OBJS))
	$(CC) $(CFLAGS) $(BENCHMARK_OBJ) $(filter-out $(BUILD_DIR)/main.o, $(OBJS)) -o $@ -lm


# Règles génériques pour la construction des fichiers objets
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS) $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Règle pour la construction du fichier objet benchmark
$(BENCHMARK_OBJ): $(BENCHMARK_SRC) $(DEPS) $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR)/*.o $(MAIN_EXEC) $(BENCHMARK_EXEC)

.PHONY: all clean
