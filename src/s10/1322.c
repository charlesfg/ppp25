#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Crie uma lista ligada para conter contactos (nome e número de telefone).
 * Mantenha a lista ordenada por ordem alfabética crescente do nome
 * (apenas uma diferença entre maiúsculas e minúsculas não faz um
 * nome ser diferente).
 * Crie funções para colocar, retirar e consultar a lista
 */
typedef struct {
  char name[100];
  long tel;
} contact;

struct list_node {
  contact value;
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

int cmp_contact(contact a, contact b) { return strcasecmp(a.name, b.name); };

// Verifica se a lista está vazia
int empty(struct list_node *list) { return list->next == NULL; }

struct list_node *query(struct list_node *list, char *name) {
  // return the first name that matches `name``
  list = list->next;  // skip head;
  while (list != NULL) {
    if (strcasecmp(list->value.name, name) == 0) {
      return list;
    }
    list = list->next;
  }
  return NULL;
}

struct list_node *delete(struct list_node *list, char *name) {
  // return the first item that matches `name``
  struct list_node *prev = list;
  list = list->next;  // skip head;

  while (list != NULL) {
    if (strcasecmp(list->value.name, name) == 0) {
      prev->next = list->next;
      list->next = NULL;
      return list;
    }
    prev = list;
    list = list->next;
  }
  return NULL;
}
// Insere o valor em ordem crescente
void insert(struct list_node *list, contact value) {
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
  while (curr != NULL && cmp_contact(curr->value, value) < 0) {
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
    printf("Nome:%20s\t%ld\n", curr->value.name, curr->value.tel);
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
    printf("|  Dados: Nome %20s\t%ld\n", atual->value.name, atual->value.tel);
    printf("|  Próx : %11p\t|\n", (void *)atual->next);
    printf("└-----------------------┘\n");
    if (atual->next != NULL) printf("            ↓\n");
    atual = atual->next;
  }

  printf("           NULL (fim da lista)\n\n");
}

int main() {
  struct list_node *lista = create();

  contact pre = {"Zig", 7875456789};
  insert(lista, pre);
  contact a = {"Charles", 975456789};
  insert(lista, a);
  contact b = {"CHARLes", 9754562289};
  insert(lista, b);
  contact c = {"Carlops", 9711562289};
  insert(lista, c);

  imprime_struct(lista);
  print(lista);
  printf("Nó:    %11p\t|\n", (void *)query(lista, "Charles"));
  delete (lista, "Charles");
  print(lista);
  clean(lista);
  return 0;
}
