#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int item_t;

typedef struct no {
  // Tipo de Dados da pilha
  item_t valor;
  struct no *proximo;
} no_t;

// ------- FUNCOES PILHAS  ------------------------
typedef struct {
  no_t *topo;
} pilha_t;

pilha_t *criaPilha() {
  pilha_t *pilha = (pilha_t *)malloc(sizeof(pilha_t));
  pilha->topo = NULL;
  return pilha;
}

int pilhaVazia(pilha_t *pilha) { return pilha->topo == NULL; }

void push(pilha_t *pilha, item_t valor) {
  no_t *novo = (no_t *)malloc(sizeof(no_t));
  novo->valor = valor;
  novo->proximo = pilha->topo;
  pilha->topo = novo;
}

item_t pop(pilha_t *pilha) {
  if (pilhaVazia(pilha)) {
    return (item_t)0;
  }
  no_t *aux = pilha->topo;
  item_t valor = aux->valor;
  pilha->topo = aux->proximo;
  free(aux);

  return valor;
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

// ---- FUNCOES FILAS  ------------------------

// Estrutura para representar a fila
typedef struct fila {
  no_t *inicio;
  no_t *fim;
} Fila;

// Função para criar uma fila vazia
Fila *criarFila() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  if (fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
  }
  return fila;
}

// Função para verificar se a fila está vazia
int vazia(Fila *fila) {
  if (fila->inicio == NULL)
    return 1;
  else
    return 0;
}

// Função para inserir um elemento na fila
void inserir(Fila *fila, item_t valor) {
  no_t *novo = (no_t *)malloc(sizeof(no_t));
  novo->valor = valor;
  novo->proximo = NULL;

  if (vazia(fila)) {
    fila->inicio = novo;
  } else {
    fila->fim->proximo = novo;
  }

  fila->fim = novo;
}

// Função para remover um elemento da fila
item_t remover(Fila *fila) {
  if (vazia(fila)) {
    printf("Erro: Fila vazia!\n");
    exit(1);
  }

  no_t *aux = fila->inicio;
  item_t valor = aux->valor;

  fila->inicio = aux->proximo;
  free(aux);

  if (fila->inicio == NULL) {
    fila->fim = NULL;
  }

  return valor;
}

// Função para mostrar os elementos da fila
void mostrarFila(Fila *fila) {
  if (vazia(fila)) {
    printf("Fila vazia!\n");
    return;
  }

  no_t *aux = fila->inicio;
  while (aux != NULL) {
    printf("%d ", aux->valor);
    aux = aux->proximo;
  }

  printf("\n");
}

void inverteFila(Fila *f) {
  pilha_t *p = criaPilha();

  while (!vazia(f)) {
    push(p, remover(f));
  }

  while (!pilhaVazia(p)) {
    inserir(f, pop(p));
  }
}

int main() {
  int n = 0;

  Fila *f = criarFila();
  printf(
      "Insira uma sequencia de inteiros para inversão: -99 para terminar.\n");

  printf("-> ");
  scanf("%d", &n);
  while (n != -99) {
    inserir(f, (item_t)n);
    printf("-> ");
    scanf("%d", &n);
  }
  mostrarFila(f);
  inverteFila(f);
  mostrarFila(f);
}
