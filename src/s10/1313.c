#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Definição do nó da lista
struct list_node {
  char str[MAX];
  struct list_node *next;
};

// Cria uma lista com nó sentinela
struct list_node *create(void) {
  struct list_node *head = (struct list_node *)malloc(sizeof(struct list_node));
  if (head == NULL) {
    printf("Erro de alocação.\n");
    exit(1);
  }
  head->next = NULL;
  return head;
}

// Insere no final da lista
void insert(struct list_node *list, char *text) {
  struct list_node *new_node =
      (struct list_node *)malloc(sizeof(struct list_node));
  if (new_node == NULL) {
    printf("Erro de alocação.\n");
    exit(1);
  }

  strncpy(new_node->str, text, MAX);
  new_node->str[MAX - 1] = '\0';  // Garantir fim da string
  new_node->next = NULL;

  struct list_node *curr = list;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
}

// Remove o primeiro elemento da lista (após o sentinela)
char *pop(struct list_node *list) {
  if (list->next == NULL) return NULL;

  struct list_node *to_remove = list->next;
  char *value = strdup(to_remove->str);  // Copia da string
  list->next = to_remove->next;
  free(to_remove);
  return value;
}

// Libera memória de toda a lista
void clean(struct list_node *list) {
  struct list_node *curr = list;
  while (curr != NULL) {
    struct list_node *tmp = curr;
    curr = curr->next;
    free(tmp);
  }
}

int main() {
  struct list_node *lista = create();
  char buffer[MAX];
  int count = 0;
  char maior_str[MAX] = "";
  size_t max_len = 0;

  printf("Digite strings (vazio para encerrar):\n");

  while (1) {
    printf("String %d: ", count + 1);
    fgets(buffer, MAX, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove '\n'

    if (strlen(buffer) == 0) break;

    insert(lista, buffer);
    count++;

    if (strlen(buffer) > max_len) {
      max_len = strlen(buffer);
      strncpy(maior_str, buffer, MAX);
      maior_str[MAX - 1] = '\0';
    }
  }

  printf("\nRetirando strings da lista:\n");
  char *s;
  while ((s = pop(lista)) != NULL) {
    printf("-> %s\n", s);
    free(s);  // liberar a string duplicada
  }

  printf("\nTotal de strings lidas: %d\n", count);
  printf("String com mais caracteres: \"%s\" (%zu caracteres)\n", maior_str,
         max_len);

  clean(lista);
  return 0;
}
