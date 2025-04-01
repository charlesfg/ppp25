#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int item_t;

typedef struct noPilha {
  // Tipo de Dados da pilha
  item_t item;
  struct noPilha *next;
} no_t;

typedef struct {
  no_t *topo;

} pilha_t;

pilha_t *criaPilha() {
  pilha_t *pilha = (pilha_t *)malloc(sizeof(pilha_t));
  pilha->topo = NULL;
  return pilha;
}

int pilhaVazia(pilha_t *pilha) { return pilha->topo == NULL; }

void push(pilha_t *pilha, item_t item) {
  no_t *novo = (no_t *)malloc(sizeof(no_t));
  novo->item = item;
  novo->next = pilha->topo;
  pilha->topo = novo;
}

item_t pop(pilha_t *pilha) {
  if (pilhaVazia(pilha)) {
    return (item_t)0;
  }
  no_t *aux = pilha->topo;
  item_t item = aux->item;
  pilha->topo = aux->next;
  free(aux);

  return item;
}

void destroiPilha(pilha_t *pilha) {
  while (!pilhaVazia(pilha)) {
    pop(pilha);
  }
  free(pilha);
}

item_t peek(pilha_t *pilha) {
  if (pilhaVazia(pilha)) {
    return (item_t)0;
  }

  return pilha->topo->item;
}

int top_dup(pilha_t *pilha) {
  if (pilhaVazia(pilha)) {
    return 0;
  }
  no_t *novo = (no_t *)malloc(sizeof(no_t));
  novo->item = pilha->topo->item;
  novo->next = pilha->topo;
  pilha->topo = novo;
  return 1;
}

int switch_top(pilha_t *pilha) {
  if (pilhaVazia(pilha)) {
    return 0;
  }
  no_t *aux = pilha->topo;
  pilha->topo = pilha->topo->next;
  aux->next = aux->next->next;
  pilha->topo->next = aux;

  return 1;
}

void print_stack(pilha_t *pilha) {
  no_t *atual = pilha->topo;
  if (atual == NULL) {
    printf("(pilha vazia)\n");
    return;
  }

  while (atual != NULL) {
    printf("|%3d", atual->item);
    atual = atual->next;
  }
  printf("|\n");
}

int main() {
  srand(time(NULL));
  printf("Testando o programa!\n");

  pilha_t *p = criaPilha();
  for (int i = 0; i < 5; i++) {
    push(p, rand() % 100);
  }
  print_stack(p);
}