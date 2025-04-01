#include <stdlib.h>

#include "pilha.h"

pilha_t *criaPilha() {
  pilha_t *p = (pilha_t *)malloc(sizeof(pilha_t));
  p->topo = NULL;
  return p;
}

int pilhaVazia(pilha_t *pilha) { return pilha->topo == NULL; }

void push(pilha_t *pilha, item_t item) {
  no_t *novo = (no_t *)malloc(sizeof(no_t));  // crio o nó
  novo->item = item;                          // copio o item
  novo->next = pilha->topo;  // mantenho o encademanento da pilha
  pilha->topo = novo;        // faço o novo item ser o topo
}

item_t pop(pilha_t *pilha) {
  if (pilhaVazia(pilha)) {
    // comportamento indefinido em muitos casos
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