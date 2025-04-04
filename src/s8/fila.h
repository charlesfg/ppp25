#ifndef __FILEH__
#define __FILEH__

#include <stdio.h>
#include <stdlib.h>

// Verifica se TYPE foi definido
#ifndef TYPE
#error "Você deve definir o tipo TYPE antes de incluir este arquivo. Ex: #define TYPE int"
#endif

// Estrutura de nó genérica
typedef struct no
{
    TYPE valor;
    struct no *proximo;
} item;

// Estrutura para representar a fila
typedef struct fila
{
    item *inicio;
    item *fim;
} Fila;

Fila *criarFila();
void inserir(Fila *fila, double valor);
double remover(Fila *fila);
void mostrarFila(Fila *fila);
int vazia(Fila *fila);
void destroi(Fila *fila);

#endif