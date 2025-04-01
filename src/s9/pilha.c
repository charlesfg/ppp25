#include <stdlib.h>
#include <stdbool.h>


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

pilha_t *criaPilha()
{
    pilha_t *pilha = (pilha_t *)malloc(sizeof(pilha_t));
    pilha->topo = NULL;
    return pilha;
}

int pilhaVazia(pilha_t *pilha)
{
    return pilha->topo == NULL;
}

void push(pilha_t *pilha, item_t item)
{
    no_t *novo = (no_t *)malloc(sizeof(no_t));
    novo->item = item;
    novo->next = pilha->topo;
    pilha->topo = novo;
}

item_t pop(pilha_t *pilha)
{
    if (pilhaVazia(pilha))
    {
        return (item_t)0;
    }
    no_t *aux = pilha->topo;
    item_t item = aux->item;
    pilha->topo = aux->next;
    free(aux);

    return item;
}

void destroiPilha(pilha_t *pilha)
{
    while (!pilhaVazia(pilha))
    {
        pop(pilha);
    }
    free(pilha);
}