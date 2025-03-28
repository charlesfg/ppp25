#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_STR 51

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 100

struct person {
  char name[MAX_NAME];
  int age;
};

struct stack_node {
  struct person *pper;
  struct stack_node *prox;
};

void init(struct stack_node **p) { *p = NULL; }

int empty(const struct stack_node *p) { return p == NULL; }

void free_person(struct person *p) { free(p); }

int size(const struct stack_node *p) {
  int count = 0;
  while (p) {
    count++;
    p = p->prox;
  }
  return count;
}

void clean(struct stack_node **p, void (*clean_person)(struct person *)) {
  while (*p) {
    struct stack_node *tmp = *p;
    *p = (*p)->prox;
    clean_person(tmp->pper);
    free(tmp);
  }
}

int push(struct stack_node **p, struct person *per) {
  struct stack_node *pnew = malloc(sizeof(struct stack_node));
  if (pnew != NULL) {
    pnew->pper = per;
    pnew->prox = *p;
    *p = pnew;
  }
  return pnew != NULL;
}

struct person *pop(struct stack_node **p) {
  if (*p == NULL) return NULL;
  struct person *reply = (*p)->pper;
  struct stack_node *tmp = *p;
  *p = (*p)->prox;
  free(tmp);
  return reply;
}

void print_person(struct person *p) {
  if (p)
    printf("%s is %d years old\n", p->name, p->age);
  else
    fprintf(stderr, "Person is NULL\n");
};

void print_stack(struct stack_node *p) {
  // p is passed by value, so we are not modifying the original stack
  while (p != NULL) {
    print_person(p->pper);
    p = p->prox;
  }
}

int main() {
  struct stack_node *pilha;
  init(&pilha);

  char entrada[MAX_STR];
  printf("Digite strings (\"fim\" para parar):\n");

  while (1) {
    printf("-> ");
    fgets(entrada, MAX_STR, stdin);
    entrada[strcspn(entrada, "\n")] = '\0';  // Remove '\n'

    if (strcmp(entrada, "fim") == 0) break;

    struct person *p = malloc(sizeof(struct person));
    if (!p) {
      fprintf(stderr, "Erro de alocação!\n");
      break;
    }
    strncpy(p->name, entrada, MAX_NAME);
    p->age = 0;  // não usamos

    if (!push(&pilha, p)) {
      fprintf(stderr, "Erro ao empilhar!\n");
      free(p);
    }
  }

  printf("\nStrings na ordem inversa:\n");
  while (!empty(pilha)) {
    struct person *p = pop(&pilha);
    printf("%s\n", p->name);
    free_person(p);
  }

  return 0;
}
