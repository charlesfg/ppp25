#ifndef __FILENANSDNASNDANSDNANSDNASNDNASNDAN_H__
#define __FILENANSDNASNDANSDNANSDNASNDNASNDAN_H__

#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar um elemento na fila
typedef struct no
{
    double valor;
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