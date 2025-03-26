#include "pilha.h"

#include <stdbool.h>
#include <stdlib.h>

stack *init() {
  stack *s = (stack *)malloc(sizeof(stack));
  s->top = NULL;
  return s;
}

int empty(stack *s) {
  // if s not defined, the stack can't be empty
  return (s != NULL) && (s->top == NULL);
}

item push(stack *s, item value) {
  stack_node *new = (stack_node *)malloc(sizeof(stack_node));
  new->value = value;
  new->next = s->top;
  s->top = new;
}

item pop(stack *s) {
  if (s == NULL || empty(s)) {
    perror("Undefined Pop!")
  }
  stack_node *aux = s->top;
  item item = aux->value;
  s->top = aux->next;
  free(aux);

  return item;
}

void clean(stack *s) {
  while (!empty(s)) {
    pop(s);
  }
  free(s);
}