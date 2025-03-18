#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar uma fila vazia
Fila *criarFila()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila)
    {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}

// Função para verificar se a fila está vazia
int vazia(Fila *fila)
{
    if (fila->inicio == NULL)
        return 1;
    else
        return 0;
}

// Função para inserir um elemento na fila
void inserir(Fila *fila, double valor)
{
    
}

// Função para remover um elemento da fila
double remover(Fila *fila)
{

    return 0.0;
}

// Função para mostrar os elementos da fila
void mostrarFila(Fila *fila)
{
}