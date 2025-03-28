# --------------------------------------------
# MAKEFILE LOCAL - s9/
# Compila os arquivos 1211_v1.c e 1211_v2.c
# --------------------------------------------

# Importa variáveis do Makefile principal
include ../common.mk

# Arquivos fonte e binários
SRC = 1211_v1.c 1211_v2.c 1212.c 
BINS = $(SRC:.c=)

# Compilar todos os programas
all: $(BINS)

# Regra geral de compilação
%: %.c
	$(CC) $(CFLAGS) $< -o $@

1212: 1212.c pilha.o
	$(CC) $(CFLAGS) $^ -o $@

pilha.o: pilha.c pilha.h
	$(CC) -c $(CFLAGS) $< 

# Limpeza dos executáveis
clean:
	rm -f $(BINS) *.o
