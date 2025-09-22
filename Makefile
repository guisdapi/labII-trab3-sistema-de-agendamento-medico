# Define as variáveis do projeto para facilitar a manutenção
EXECUTABLE = trab3
SOURCE_DIR = source
INCLUDE_DIR = include

# Define o compilador e as flags
CC = gcc
CFLAGS = -Wall -I$(INCLUDE_DIR)

# Encontra todos os arquivos .c na pasta 'source'
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)

# Cria a lista de arquivos objeto (.o) correspondentes aos arquivos .c
OBJECTS = $(patsubst $(SOURCE_DIR)/%.c,%.o,$(SOURCES))

# O alvo 'all' (o padrão que o make vai executar se você só digitar 'make')
all: $(EXECUTABLE)

# Regra para linkar os arquivos objeto e criar o executável
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Regra para compilar cada arquivo .c em um .o
%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos temporários (.o) e o executável
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)