# Define as variáveis do projeto para facilitar a manutenção
EXECUTABLE = trab3
SOURCE_DIR = source
BUILD_DIR = build
INCLUDE_DIR = include

# Define o compilador e as flags
CC = gcc
CFLAGS = -Wall -I$(INCLUDE_DIR)

# Encontra todos os arquivos .c na pasta 'source'
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)

# Cria a lista de arquivos objeto (.o) no diretório de build
OBJECTS = $(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

# O alvo 'all' (o padrão que o make vai executar se você só digitar 'make')
all: $(BUILD_DIR) $(EXECUTABLE)

# Regra para criar o diretório de build se ele não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Regra para linkar os arquivos objeto e criar o executável
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Regra para compilar cada arquivo .c em um .o e colocar na pasta de build
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ---
# Regras para execução e limpeza
# ---

# Regra para executar o programa
.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Regra para limpar os arquivos temporários (.o) e o executável
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

# COMANDOS:
# make - compila
# make run - roda o programa
# make clean - remove a pasta build