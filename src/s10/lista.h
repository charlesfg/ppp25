#ifndef __LISTA__H
#define __LISTA__H

#define MAX 100

struct person {
  char name[MAX];
  int age;
};

struct list_node {
  struct person per;
  struct list_node *next;
};

struct list_node *create(void);
int empty(struct list_node *list);
struct list_node *clean(struct list_node *list);
void search(struct list_node *list, char *key, struct list_node **previous,
            struct list_node **current);
void delete(struct list_node *list, char *key);
void insert(struct list_node *list, struct person p1);
void print_person(struct person p);
void print(struct list_node *list);

#endif