#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 51

typedef char *item_t;

typedef struct noPilha {
  item_t item;
  struct noPilha *next;
} no_t;

typedef struct {
  no_t *topo;
} pilha_t;

pilha_t *criaPilha() {
  pilha_t *pilha = malloc(sizeof(pilha_t));
  pilha->topo = NULL;
  return pilha;
}

int pilhaVazia(pilha_t *pilha) { return pilha->topo == NULL; }

void push(pilha_t *pilha, item_t item) {
  no_t *novo = malloc(sizeof(no_t));
  novo->item = item;
  novo->next = pilha->topo;
  pilha->topo = novo;
}

item_t pop(pilha_t *pilha) {
  if (pilhaVazia(pilha)) return NULL;

  no_t *aux = pilha->topo;
  item_t item = aux->item;
  pilha->topo = aux->next;
  free(aux);
  return item;
}

void destroiPilha(pilha_t *pilha) {
  while (!pilhaVazia(pilha)) {
    char *str = pop(pilha);
    free(str);
  }
  free(pilha);
}

int tamanhoPilha(pilha_t *pilha) {
  int count = 0;
  for (no_t *n = pilha->topo; n != NULL; n = n->next) count++;
  return count;
}

char *maiorString(pilha_t *pilha) {
  if (pilhaVazia(pilha)) return NULL;
  no_t *n = pilha->topo;
  char *maior = n->item;
  for (; n != NULL; n = n->next) {
    if (strlen(n->item) > strlen(maior)) {
      maior = n->item;
    }
  }
  return maior;
}

char *menorString(pilha_t *pilha) {
  if (pilhaVazia(pilha)) return NULL;
  no_t *n = pilha->topo;
  char *menor = n->item;
  for (; n != NULL; n = n->next) {
    if (strlen(n->item) < strlen(menor)) {
      menor = n->item;
    }
  }
  return menor;
}

void exibirAjuda() {
  printf("Comandos disponíveis (use prefixo 'cmd:'):\n");
  printf("  cmd:len       → mostra quantas strings estão na pilha\n");
  printf("  cmd:biggest   → mostra a maior string (em tamanho)\n");
  printf("  cmd:smallest  → mostra a menor string (em tamanho)\n");
  printf("  cmd:help      → mostra esta ajuda\n");
  printf("  fim           → encerra o programa\n");
}

// ========== FUNÇÃO PRINCIPAL ==========

int main() {
  pilha_t *pilha = criaPilha();
  char entrada[MAX_STR];

  printf(
      "Digite strings ou comandos (prefixo \"cmd:\"). Digite \"fim\" para "
      "sair.\n");

  while (1) {
    printf("-> ");
    fgets(entrada, MAX_STR, stdin);
    entrada[strcspn(entrada, "\n")] = '\0';  // remove '\n'

    if (strcmp(entrada, "fim") == 0) break;

    if (strncmp(entrada, "cmd:", 4) == 0) {
      char *comando = entrada + 4;

      if (strcmp(comando, "len") == 0) {
        printf("Tamanho da pilha: %d\n", tamanhoPilha(pilha));
      } else if (strcmp(comando, "biggest") == 0) {
        char *maior = maiorString(pilha);
        if (maior)
          printf("Maior string: \"%s\" (%lu caracteres)\n", maior,
                 strlen(maior));
        else
          printf("A pilha está vazia.\n");
      } else if (strcmp(comando, "smallest") == 0) {
        char *menor = menorString(pilha);
        if (menor)
          printf("Menor string: \"%s\" (%lu caracteres)\n", menor,
                 strlen(menor));
        else
          printf("A pilha está vazia.\n");
      } else if (strcmp(comando, "help") == 0) {
        exibirAjuda();
      } else {
        printf("Comando desconhecido: %s. Use cmd:help para ajuda.\n", comando);
      }
    } else {
      // É uma string a ser empilhada
      char *str_dup = malloc(strlen(entrada) + 1);
      if (!str_dup) {
        fprintf(stderr, "Erro de alocação!\n");
        break;
      }
      strcpy(str_dup, entrada);
      push(pilha, str_dup);
    }
  }

  printf("\nDesempilhando todas as strings:\n");
  while (!pilhaVazia(pilha)) {
    char *str = pop(pilha);
    printf("%s\n", str);
    free(str);
  }

  destroiPilha(pilha);
  return 0;
}