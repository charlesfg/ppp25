# --------------------------------------------
# MAKEFILE LOCAL - s10/
# Compila os arquivos *.c
# --------------------------------------------

# Importa variáveis do Makefile principal
include ../common.mk

# Arquivos fonte e binários
SRC = 1311.c 1312.c 1313.c 1322.c 1324.c 1325.c teste.c
BINS = $(SRC:.c=)

# Compilar todos os programas
all: $(BINS)

# Regra geral de compilação
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Limpeza dos executáveis
clean:
	rm -f $(BINS) *.o 
	rm -rf *dSYM

