#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list_node *create(void) {
  struct list_node *aux;
  // Create header node
  struct person p1 = {"", 0};
  aux = (struct list_node *)malloc(sizeof(struct list_node));
  if (aux != NULL) {
    aux->per = p1;
    aux->next = NULL;
  }
  return aux;
}

int empty(struct list_node *list) { return list->next == NULL; }

struct list_node *clean(struct list_node *list) {
  while (list != NULL) {
    struct list_node *temp_ptr = list;
    list = list->next;
    free(temp_ptr);
  }
  return NULL;
}

// Assumes the list is sorted by name
void search(struct list_node *list, char *key, struct list_node **previous,
            struct list_node **current) {
  *previous = list;
  *current = list->next;
  while ((*current) != NULL && strcmp((*current)->per.name, key) < 0) {
    *previous = *current;
    *current = (*current)->next;
  }
}

void delete(struct list_node *list, char *key) {
  struct list_node *previous, *current;
  search(list, key, &previous, &current);
  if (current != NULL && strcmp(current->per.name, key) == 0) {
    // Found the node to delete
    previous->next = current->next;
    free(current);
  }
}

// Assumes the list is sorted by name and cannot handle duplicate names
void insert(struct list_node *list, struct person p1) {
  struct list_node *node, *previous, *useless;
  node = (struct list_node *)malloc(sizeof(struct list_node));
  if (node != NULL) {
    node->per = p1;
    search(list, p1.name, &previous, &useless);
    node->next = previous->next;
    previous->next = node;
  }
}

void print_person(struct person p) {
  printf("%s is %d years old\n", p.name, p.age);
};

void print(struct list_node *list) {
  struct list_node *aux = list->next; /* Skips header */
  while (aux) {
    print_person(aux->per);
    aux = aux->next;
  }
}
