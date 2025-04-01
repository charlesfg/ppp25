#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char item_t;

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

void imprime_invertido(char *cadeia) {
  char *c = cadeia;
  pilha_t *p = criaPilha();

  while (*c != 0) {
    push(p, *c);
    c++;
  }
  while (!pilhaVazia(p)) {
    printf("%c", pop(p));
  }
  printf("\n");
}

int main() {
  char cadeia[100];

  printf("Insira uma cadeia de caracteres para inversão\n");
  fgets(cadeia, 100, stdin);
  cadeia[strcspn(cadeia, "\n")] = '\0';  // Remove '\n'

  imprime_invertido(cadeia);
}

//"CASA CARA"->"ARAC ASAC"