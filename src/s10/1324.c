#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Construa um programa que converta a informação
 * contida numa pilha para uma uma lista ligada.
 */

typedef int item;

typedef struct no {
  // Tipo de Dados da pilha
  item item;
  struct no *next;
} node;

// Note that our stack in THIS implementation
// have ALSO an HEAD to mark the begin
node *make_stack() {
  node *s = (node *)malloc(sizeof(node));
  s->next = NULL;
  return s;
}

int is_stack_empty(node *s) { return s->next == NULL; }

void push(node *s, item item) {
  node *new = (node *)malloc(sizeof(node));
  new->item = item;
  new->next = s->next;
  s->next = new;
}

item pop(node *s) {
  if (is_stack_empty(s)) {
    return (item)0;
  }
  node *aux = s->next;
  item item = aux->item;
  s->next = aux->next;
  free(aux);

  return item;
}

void destroy_stack(node *s) {
  while (!is_stack_empty(s)) {
    pop(s);
  }
  free(s);
}

void print_stack(node *top) {
  printf("Top ->\n");
  // We use top->next to skip the head
  while (top->next != NULL) {
    printf("  +-----+\n");
    printf("  | %3d |\n", top->next->item);
    printf("  +-----+\n");
    printf("    |\n");
    top = top->next;
  }
  printf("   NULL\n");
}

node *make_list() {
  node *l = (node *)malloc(sizeof(node));
  l->item = 0;
  l->next = NULL;
  return l;
}

int is_list_empty(node *l) { return l->next == NULL; }

void search(node *l, item v, node **prev, node **cur) {
  *prev = l;
  *cur = l->next;
  while ((*cur) != NULL && (*cur)->item < v) {
    *prev = *cur;
    *cur = (*cur)->next;
  }
}

void insert(node *l, item v) {
  node *n = (node *)malloc(sizeof(node));
  n->item = v;
  node *p, *c;
  search(l, v, &p, &c);
  n->next = p->next;
  p->next = n;
}

void print_list(node *head) {
  while (head->next != NULL) {
    printf("[ %3d ] -> ", head->next->item);
    head = head->next;
  }
  printf("NULL\n");
}

void destroy_list(node *l) {
  node *to_del;
  while (l->next != NULL) {
    to_del = l->next;
    l->next = l->next->next;
    free(to_del);
  }
  free(l);
}

int main() {
  // create the stack
  node *s = make_stack();
  node *l = make_list();
  // add values to stack
  push(s, 2);
  push(s, 5);
  push(s, 1);
  push(s, 4);
  push(s, 3);

  print_stack(s);

  while (!is_stack_empty(s)) {
    insert(l, pop(s));
  }

  print_list(l);
  destroy_stack(s);
  destroy_list(l);
}