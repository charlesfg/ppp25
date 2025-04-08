#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista
struct list_node {
  double value;
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
    printf("%.2lf ", curr->value);
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
    printf("|  Dados: %11.2lf\t|\n", atual->value);
    printf("|  Próx : %11p\t|\n", (void *)atual->next);
    printf("└-----------------------┘\n");
    if (atual->next != NULL) printf("            ↓\n");
    atual = atual->next;
  }

  printf("           NULL (fim da lista)\n\n");
}

int main() {
  int N;
  double num;
  printf("Quantos valores deseja inserir? ");
  scanf("%d", &N);

  struct list_node *lista = create();

  for (int i = 0; i < N; i++) {
    printf("Digite o valor %d: ", i + 1);
    scanf("%lf", &num);
    insert(lista, num);
  }

  imprime_struct(lista);
  print(lista);
  clean(lista);
  return 0;
}
