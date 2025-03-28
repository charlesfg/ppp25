# Compilador
CC = gcc

# Flags de compilação:
# -Wall: mostra todos os avisos
# -Wextra: mostra avisos adicionais
# -std=c99: usa o padrão da linguagem C99
CFLAGS = -Wall -g -Wextra -std=c99

# Flags de linkagem (vazio por enquanto)
LDFLAGS = -lm