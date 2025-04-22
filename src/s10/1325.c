#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Crie uma função que, dadas duas listas ligadas de palavras,
 * concatene as duas listas, gerando o resultado na primeira lista,
 * eliminando a segunda lista. As palavras devem ficar ordenadas
 *  por ordem alfabética na lista final. No caso de haver palavras
 * repetidas, estas só devem aparecer uma vez na lista final
 */

#define ITEM_SZ 20

typedef char item[ITEM_SZ];

typedef struct no {
  // Tipo de Dados da pilha
  item item;
  struct no *next;
} node;

node *make_list() {
  node *l = (node *)malloc(sizeof(node));
  memset(l->item, 0, sizeof(l->item));
  l->next = NULL;
  return l;
}

int is_list_empty(node *l) { return l->next == NULL; }

void search(node *l, item v, node **prev, node **cur) {
  *prev = l;
  *cur = l->next;
  while ((*cur) != NULL && strcmp((*cur)->item, v) < 0) {
    *prev = *cur;
    *cur = (*cur)->next;
  }
}

void insert(node *l, item v) {
  node *n = (node *)malloc(sizeof(node));
  strncpy(n->item, v, sizeof(n->item));
  node *p, *c;
  search(l, v, &p, &c);
  n->next = p->next;
  p->next = n;
}

void print_list(node *head) {
  while (head->next != NULL) {
    printf("[%s] -> ", head->next->item);
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

void merge_list(node *f, node *s) {
  // se a lista é vazia não tem o que fazer
  if (is_list_empty(s)) return;

  // fazemos skip do header
 
  while (!is_list_empty(s)) {
    node *prev, *cur;
    prev = cur = NULL;
    search(f, s->item, &prev, &cur);
    // se o ponteiro está definido
    // a string não é vazia
    // os items são diferentes, posso prosseguir, senão, ignoro
    if (prev && strlen(s->item) && strcmp(s->item, prev->item)) {
      insert(f, s->item);
      cur = s;
      s = s->next;
      free(cur);
    }
  }
}

int main() {
  // create the stack

  node *fst = make_list();

  insert(fst, "eles");
  insert(fst, "passarão,");
  insert(fst, "eu,");
  insert(fst, "passarinho!");
  print_list(fst);

  node *scnd = make_list();
  insert(scnd, "eu");
  insert(scnd, "faço");
  insert(scnd, "versos");
  insert(scnd, "como");
  insert(scnd, "quem");
  insert(scnd, "chora");
  print_list(scnd);

  merge_list(fst, scnd);

  print_list(fst);
  destroy_list(fst);
}