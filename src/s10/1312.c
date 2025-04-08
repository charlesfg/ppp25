#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definindo a estrutura do nó da lista
struct list_node {
  int value;
  struct list_node *next;
};

// Cria a lista com um nó sentinela
struct list_node *create(void) {
  struct list_node *head = (struct list_node *)malloc(sizeof(struct list_node));
  if (head == NULL) {
    printf("Erro de alocação de memória.\n");
    exit(1);
  }
  head->next = NULL;
  return head;
}

// Verifica se a lista está vazia
int empty(struct list_node *list) { return list->next == NULL; }

// Insere o valor em ordem crescente
void insert(struct list_node *list, double value) {
  struct list_node *new_node =
      (struct list_node *)malloc(sizeof(struct list_node));
  if (new_node == NULL) {
    printf("Erro de alocação de memória.\n");
    exit(1);
  }
  new_node->value = value;

  struct list_node *prev = list;
  struct list_node *curr = list->next;

  // Encontrar a posição correta para inserção (ordem crescente)
  while (curr != NULL && curr->value < value) {
    prev = curr;
    curr = curr->next;
  }

  new_node->next = curr;
  prev->next = new_node;
}

// Imprime todos os elementos da lista
void print(struct list_node *list) {
  struct list_node *curr = list->next;
  printf("Valores na lista (ordem crescente):\n");
  while (curr != NULL) {
    printf("%5d ", curr->value);
    curr = curr->next;
  }
  printf("\n");
}

// Libera a memória da lista
void clean(struct list_node *list) {
  struct list_node *curr = list->next;
  struct list_node *tmp;
  while (curr != NULL) {
    tmp = curr;
    curr = curr->next;
    free(tmp);
  }
  free(list);
}

void imprime_struct(struct list_node *lista) {
  struct list_node *atual = lista;

  printf("\nRepresentação gráfica da lista encadeada:\n");

  while (atual != NULL) {
    printf("┌-----------------------┐\n");
    printf("|  Nó:    %11p\t|\n", (void *)atual);
    printf("|  Dados: %11d\t|\n", atual->value);
    printf("|  Próx : %11p\t|\n", (void *)atual->next);
    printf("└-----------------------┘\n");
    if (atual->next != NULL) printf("            ↓\n");
    atual = atual->next;
  }

  printf("           NULL (fim da lista)\n\n");
}

float calcula_media(struct list_node *l) {
  int soma = 0;
  int num_elem = 0;

  if (empty(l)) {
    return 0.0f;
  }

  // skip header
  l = l->next;
  while (l != NULL) {
    soma += l->value;
    num_elem++;
    l = l->next;
  }
  return ((float)soma) / num_elem;
}

int pega_maior(struct list_node *l) {
  int maior = 0;

  if (empty(l)) {
    return maior;
  }

  // skip header
  l = l->next;
  while (l != NULL) {
    if (l->value > maior) maior = l->value;
    l = l->next;
  }
  return maior;
}

int pega_menor(struct list_node *l) {
  int menor = INT32_MAX;

  if (empty(l)) {
    return menor;
  }

  // skip header
  l = l->next;
  while (l != NULL) {
    if (l->value < menor) menor = l->value;
    l = l->next;
  }
  return menor;
}

#define NUM_ELEM 15

int main() {
  srand(time(NULL));
  printf("Gerando %d elemntos para  lista!", NUM_ELEM);

  struct list_node *lista = create();

  for (int i = 0; i < NUM_ELEM; i++) {
    insert(lista, rand() % 100);
  }

  imprime_struct(lista);
  printf("O maior elemento da lista é: '%3d'\n", pega_maior(lista));
  printf("O menor elemento da lista é: '%3d'\n", pega_menor(lista));
  printf("O valor médio dos elementos da lista é: '%5.2f'\n",
         calcula_media(lista));

  print(lista);
  clean(lista);
  return 0;
}
