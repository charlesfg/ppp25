# =============================================================
# MAKEFILE PRINCIPAL – TUTORIAL BÁSICO PARA INICIANTES
# =============================================================
#
# 📘 O que é um Makefile?
# -----------------------
# É um arquivo de automação que descreve como compilar e montar
# programas em C (ou outras linguagens). Ele evita que você tenha
# que digitar comandos longos no terminal toda vez.
#
# Em vez de usar:
#     gcc -Wall -std=c99 -o meu_programa main.c util.c
#
# Você pode simplesmente escrever:
#     make meu_programa
#
# 📌 Como funciona o Make?
# ------------------------
# O `make` usa regras com esta estrutura:
#
# alvo: dependências
# <tab> comando para gerar o alvo
#
# Exemplo:
#   main.o: main.c
#       gcc -c main.c -o main.o
#
# Esse comando diz:
# "Para gerar main.o, use o arquivo main.c com esse comando".
#
# 🧩 Variáveis Automáticas
# ------------------------
# $@ → representa o nome do alvo (target)
# $< → representa a primeira dependência
# $^ → representa todas as dependências
#
# Exemplo:
#   meu_programa: main.c
#       gcc $< -o $@
#
# É o mesmo que:
#   gcc main.c -o meu_programa
#
# ✅ Vantagens do Make
# ---------------------
# - Automatiza a compilação
# - Evita recompilar o que não mudou
# - Organiza melhor projetos grandes
# - Permite reutilizar regras e variáveis
#
# -------------------------------------------------------------
# VARIÁVEIS GLOBAIS DO PROJETO
# -------------------------------------------------------------

# Compilador
CC = gcc

# Flags de compilação:
# -Wall: mostra todos os avisos
# -Wextra: mostra avisos adicionais
# -std=c99: usa o padrão da linguagem C99
CFLAGS = -Wall -g -Wextra -std=c99

# Flags de linkagem (vazio por enquanto)
LDFLAGS = -lm

# Diretórios usados no projeto
SRC_DIR = s9      # Onde estão os programas a serem compilados
BIN_DIR = bin     # Onde ficariam os executáveis (não usado ainda)

# -------------------------------------------------------------
# REGRAS DO MAKEFILE
# -------------------------------------------------------------

# Alvo padrão: compilar todos os programas da pasta s9
.PHONY: all
all:
	$(MAKE) -C $(SRC_DIR)

# Limpar arquivos gerados na pasta s9
.PHONY: clean
clean:
	$(MAKE) -C $(SRC_DIR) clean


# -------------------------------------------------------------
# Limpeza em todos os subdiretórios com Makefile
# -------------------------------------------------------------

# Encontra todos os diretórios com um Makefile (exceto este próprio)
MAKE_DIRS := $(shell find . -mindepth 2 -name Makefile -exec dirname {} \;)

.PHONY: clean
clean:
	@echo "Limpando todos os subdiretórios com Makefile..."
	@for dir in $(MAKE_DIRS); do \
		echo "-> Limpando $$dir"; \
		$(MAKE) -C $$dir clean; \
	done

