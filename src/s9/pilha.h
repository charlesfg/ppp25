#ifndef __PILHA__H
#define __PILHA__H

#include <stdlib.h>

/*
    Substitua o tipo item_t pelo tipo de dados que deseja empilhar
    ex.:
    typedef char item_t;
    typedef struct pessoa{
        char *nome;
        int idade;
    } item_t;
    etc
*/
typedef int item_t;

typedef struct noPilha
{
    // Tipo de Dados da pilha
    item_t item;
    struct noPilha *next;
} no_t;

typedef struct
{
    no_t *topo;

} pilha_t;

pilha_t *criaPilha();
int pilhaVazia(pilha_t *p);
void push(pilha_t *p, item_t item);
item_t pop(pilha_t *p);
void destroiPilha(pilha_t *p);

#endif
