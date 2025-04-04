# Makefile para Iniciantes em Programacao

## O que é um Makefile?

Um **Makefile** é um arquivo de texto que descreve como compilar e construir um programa automaticamente. Ele é utilizado pela ferramenta **make**, que analisa quais arquivos precisam ser recompilados e executa os comandos necessários de forma eficiente.

Imagine que você tenha vários arquivos `.c` e `.h` e precisa compilar tudo. Em vez de digitar manualmente comandos `gcc` no terminal, você escreve um Makefile e simplesmente roda:

```bash
make
```

O `make` se encarrega de tudo para você, recompilando apenas o que for necessário.

---

## Estrutura Básica de um Makefile

### Sintaxe:

```make
alvo: dependencias
<TAB>comandos
```

- **alvo (target)**: é o que você quer construir (ex: um executável).
- **dependências**: arquivos que o alvo depende (ex: arquivos .c ou .h).
- **comando**: instruções que devem ser executadas (ex: linha do gcc).

### Exemplo simples:
```make
main: main.c
	gcc -o main main.c
```

Para executar, digite:
```bash
make
```
Isso gera o executável `main`.

---

## Variáveis em Makefile

Você pode definir variáveis para tornar o Makefile mais legível e reutilizável:

```make
CC = gcc
CFLAGS = -Wall -g

main: main.c
	$(CC) $(CFLAGS) -o main main.c
```

Agora, se quiser trocar o compilador ou adicionar flags, basta alterar a variável.

---

## Variáveis automáticas

Make possui variáveis automáticas que facilitam a escrita das regras ([veja com mais detalhes ao final do documento](#tabela-de-variáveis-automáticas)):

| Variável | Significado |
|----------|-------------|
| `$@`     | Nome do alvo |
| `$<`     | Primeira dependência |
| `$^`     | Todas as dependências |

### Exemplo:
```make
main: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<
```

---

## Regras .PHONY

`.PHONY` indica que uma regra não gera um arquivo com o mesmo nome. Isso é usado para comandos como `clean`, `run`, etc.

```make
.PHONY: clean run

clean:
	rm -f *.o main

run:
	./main
```

---

## Como passar variáveis pela linha de comando

Você pode sobrescrever variáveis ao rodar o `make`:

```bash
make CFLAGS="-Wall -O2"
```

Isso substitui o valor definido no Makefile.

---

## Mostrar os comandos sem executar

Use a opção `-n`:
```bash
make -n
```

Isso mostra o que *seria* feito, sem executar os comandos. ótimo para testar.

---

## Regras automáticas (inference rules)

O `make` tem regras embutidas:
```make
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```

Permite compilar qualquer `.c` para `.o` automaticamente.

---

## Projeto exemplo passo a passo

Arquivos:
```
- main.c
- util.c
- util.h
- Makefile
```

**Makefile:**
```make
CC = gcc
CFLAGS = -Wall -g
OBJ = main.o util.o
TARGET = prog

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)
```

---

## Dicas e boas práticas

- Use variáveis para não repetir nomes.
- Use `.PHONY` para comandos auxiliares.
- Prefira compilar arquivos separadamente (`.o`) e linkar no final.
- Mantenha o Makefile simples e organizado.

---

## Tópicos mais avançados

### Includes
Você pode usar `include` para carregar outras configurações:
```make
include config.mk
```

### Detectar sistema operacional
```make
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
    CC = gcc
endif
```

### Criar diretório de objetos
```make
OBJDIR = obj
OBJS = $(OBJDIR)/main.o $(OBJDIR)/util.o

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```

---

Makefiles são essenciais para qualquer programador C/C++ e podem ser adaptadas para outros projetos também.



---

## Tabela de Variáveis Automáticas

| Variável | Significado | Importância | Exemplo (contexto real) | Expansão na prática |
|----------|-------------|-------------|--------------------------|----------------------|
| `$@`     | Nome do alvo (target) atual | 🔥 Muito usada para gerar nomes de arquivos ou executáveis | `main: main.o` → `gcc -o $@ main.o` | `$@` → `main` |
| `$<`     | Primeira dependência (input) da regra | 🔥 Útil em regras de compilação simples | `main.o: main.c` → `gcc -c $<` | `$<` → `main.c` |
| `$^`     | Todas as dependências, separadas por espaço (sem duplicatas) | 🔥 Excelente para linkar múltiplos objetos | `prog: main.o utils.o` → `gcc -o $@ $^` | `$^` → `main.o utils.o` |
| `$?`     | Lista de dependências mais novas que o alvo (ou seja, arquivos que mudaram) | 💡 Usado para compilar apenas arquivos modificados | `prog: main.o utils.o` → `gcc -o $@ $?` | Se só `utils.o` mudou, então `$?` → `utils.o` |
| `$*`     | Nome do arquivo sem sufixo de extensão (útil em regras genéricas) | 💡 Usado para gerar nomes com base no nome do arquivo | `%.o: %.c` → `$*` → `main`, se `$<` for `main.c` | |
| `$$`     | Para representar um símbolo de cifrão `$` em comandos shell | 💡 Necessário ao usar variáveis de shell (como `$$PATH`) | `@echo \"PID: $$\"` | Shell vê apenas 1 `$` → `$` |

---

## 🧠 Explicações com Exemplos Concretos

### 🔹 `$@` – Nome do alvo (target)

```make
prog: main.o utils.o
	$(CC) -o $@ $^
```

Durante a execução, se `make prog` for chamado:
- `$@` → `prog`
- Comando executado: `gcc -o prog main.o utils.o`

### 🔹 `$<` – Primeira dependência

```make
main.o: main.c
	$(CC) -c $<
```

- `$<` → `main.c`
- Comando: `gcc -c main.c`

### 🔹 `$^` – Todas as dependências

```make
prog: main.o utils.o
	$(CC) -o $@ $^
```

- `$^` → `main.o utils.o`
- Comando: `gcc -o prog main.o utils.o`

### 🔹 `$?` – Apenas os arquivos modificados

```make
prog: main.o utils.o
	@echo \"Arquivos modificados: $?\"
```

Se só `main.o` foi recompilado:
- `$?` → `main.o`

Isso pode ser útil para **compilar só o que mudou**, economizando tempo.

### 🔹 `$*` – Nome base (sem extensão)

```make
%.o: %.c
	$(CC) -c $< -o $@
```

Se o alvo for `main.o`:
- `$*` → `main`
- `$<` → `main.c`
- `$@` → `main.o`

---

## 🧪 Demonstração prática com Makefile

```make
CC = gcc
CFLAGS = -Wall -g

SRC = main.c utils.c
OBJ = $(SRC:.c=.o)

prog: $(OBJ)
	@echo \"Target: $@\"
	@echo \"Dependências: $^\"
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@echo \"Compilando $< para gerar $@\"
	$(CC) $(CFLAGS) -c $< -o $@
```

---

## 📌 Dicas para usar variáveis automáticas

- Use **`$@` sempre que for gerar um arquivo de saída** (alvo).
- Use **`$<` quando tiver uma única dependência**, como ao compilar `.c` para `.o`.
- Use **`$^` para combinar múltiplos `.o` em um executável**.
- Use **`$*` em regras genéricas** com `%.ext`.
- Use **`$?` em regras que só devem rodar para arquivos modificados**.
