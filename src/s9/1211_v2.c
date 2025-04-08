#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 51


typedef char *   item_t;

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
// =======================================================

int main() {
  pilha_t *pilha = criaPilha();
  char entrada[MAX_STR];

  printf("Digite strings (\"fim\" para parar):\n");

  while (1) {
    printf("-> ");
    fgets(entrada, MAX_STR, stdin);
    entrada[strcspn(entrada, "\n")] = '\0';

    if (strcmp(entrada, "fim") == 0) break;

    char *str_dup = malloc(strlen(entrada) + 1);
    if (!str_dup) {
      fprintf(stderr, "Erro de alocação!\n");
      break;
    }
    strcpy(str_dup, entrada);

    push(pilha, str_dup);
  }

  printf("\nStrings na ordem inversa:\n");
  while (!pilhaVazia(pilha)) {
    char *str = pop(pilha);
    printf("%s\n", str);
    free(str);
  }

  destroiPilha(pilha);
  return 0;
}
