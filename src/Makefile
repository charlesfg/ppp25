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



# estão definidas em um arquivo à parte só de configurações
include common.mk



# -------------------------------------------------------------
# Limpeza em todos os subdiretórios com Makefile
# -------------------------------------------------------------

# Encontra todos os diretórios com um Makefile (exceto este próprio)
MAKE_DIRS := $(shell find . -mindepth 2 -name Makefile -exec dirname {} \;)

SUBDIRS := $(wildcard */)
MAKEFILES := $(foreach dir, $(SUBDIRS), $(wildcard $(dir)Makefile))



# -------------------------------------------------------------
# REGRAS DO MAKEFILE
# -------------------------------------------------------------

# Alvo padrão: compilar todos os programas da pasta s9
.PHONY: all  $(SUBDIRS) cleanbin clean

all: $(MAKE_DIRS)
	$(MAKE) -C $(MAKE_DIRS) all



.PHONY: clean cleanbin
clean:
	@echo "Limpando todos os subdiretórios com Makefile..."
	@for dir in $(MAKE_DIRS); do \
		echo "-> Limpando $$dir"; \
		$(MAKE) -C $$dir/ clean; \
	done

$(SUBDIRS):
	@echo "Building in $@"
	$(MAKE) -C $@/Makefile


cleanrepo: cleanbin
	@echo ">> Removing every '*.o' and '*.dSYM' ..."
	@find . -type d -name '*.dSYM' -exec rm -rf {}  \;
	@find . -type f -name '*.o' -exec rm -f {}  \;


cleanbin:
	@echo ">> Creating dummy C program..."
	@echo 'int main() { return 0; }' > .dummy.c

	@echo ">> Compiling dummy binary..."
	@$(CC) .dummy.c -o .dummy_binary

	@echo ">> Detecting binary type..."
	@TYPE=$$(file -b .dummy_binary | cut -d',' -f1); \
	echo ">> Detected binary type: $$TYPE"; \
	echo ">> Searching and removing matching files..."; \
	find . -type f ! -name ".dummy_binary" ! -name "Makefile" -exec sh -c 'file -b "$$0" | grep -q "^'"$$TYPE"'" && echo "Removing $$0" && rm -f "$$0"' {} \;

	@echo ">> Cleaning up dummy files..."
	@rm -f .dummy.c .dummy_binary
