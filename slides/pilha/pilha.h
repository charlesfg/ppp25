#ifndef __PILHA__H
#define __PILHA__H

#define MAX_NAME 100

typedef struct pessoa {
  char name[MAX_NAME];
  int age;
} item;

typedef struct node {
  // Tipo de Dados da pilha
  item value;
  struct node *next;
} stack_node;

typedef struct {
  stack_node *top;
} stack;

stack *init();
int empty(stack *p);
item push(stack *p, item value);
item pop(stack *p);
void clean(stack *p);

#endif
