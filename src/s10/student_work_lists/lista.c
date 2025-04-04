#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list_node *create(void) {
  printf("[create] NÃO IMPLEMENTADO\n");
  return NULL;
}

int empty(struct list_node *list) {
  printf("[empty] NÃO IMPLEMENTADO\n");
  return -1;  // valor inválido, para indicar que ainda não foi implementado
}

struct list_node *clean(struct list_node *list) {
  printf("[clean] NÃO IMPLEMENTADO\n");
  return NULL;
}

void search(struct list_node *list, char *key, struct list_node **previous,
            struct list_node **current) {
  printf("[search] NÃO IMPLEMENTADO\n");
  *previous = NULL;
  *current = NULL;
}

void delete(struct list_node *list, char *key) {
  printf("[delete] NÃO IMPLEMENTADO\n");
}

void insert(struct list_node *list, struct person p1) {
  printf("[insert] NÃO IMPLEMENTADO\n");
}

void print_person(struct person p) {
  printf("[print_person] NÃO IMPLEMENTADO\n");
}

void print(struct list_node *list) { printf("[print] NÃO IMPLEMENTADO\n"); }
