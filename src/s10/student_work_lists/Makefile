# ----------------------------------------
# MAKEFILE PARA PROJETO DE LISTA EM C
# ----------------------------------------

# 1. O que é um Makefile?
# -------------------------
# Um Makefile é um arquivo de instruções usado pelo comando `make`.
# Ele automatiza o processo de compilação de programas, economizando tempo.
# Em vez de digitar longos comandos gcc no terminal, você pode simplesmente digitar:
#     make
# E o Makefile se encarrega do resto!

# 2. Variáveis comuns em Makefiles
# ---------------------------------
# Podemos definir variáveis para reutilizar comandos e nomes.
CC = gcc                # Compilador a ser usado
CFLAGS = -Wall -g       # Opções de compilação (-Wall: mostra todos os avisos, -g: debug)
TARGET = testa_lista    # Nome do executável final
OBJS = lista.o testa_lista.o  # Objetos a serem compilados

# 3. Regra principal: compilar tudo
# -----------------------------------
# A primeira regra do Makefile é a padrão, usada quando digitamos apenas `make`.
# A sintaxe geral de uma regra é:
# alvo: dependências
# <tabulação> comando

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 4. Regras para compilar os arquivos .c individualmente
# --------------------------------------------------------

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

testa_lista.o: testa_lista.c lista.h
	$(CC) $(CFLAGS) -c testa_lista.c

# 5. Regra de limpeza (make clean)
# ---------------------------------
# Essa regra é útil para remover os arquivos gerados na compilação.
# Digite `make clean` para limpar tudo.

clean:
	rm -f *.o $(TARGET)

# 6. Variáveis automáticas úteis (explicação)
# -------------------------------------------
# $@ : representa o nome do alvo (ex: testa_lista)
# $< : primeira dependência (ex: lista.c)
# $^ : todas as dependências (ex: lista.o testa_lista.o)
#
# Exemplo alternativo de regra usando variáveis automáticas:
# $(CC) $(CFLAGS) -o $@ $^


test: testa_lista
	./testa_lista

# FIM DO MAKEFILE

