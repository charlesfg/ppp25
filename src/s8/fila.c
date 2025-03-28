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
    item *novo = (item *)malloc(sizeof(item));
    novo->valor = valor;
    novo->proximo = NULL;

    if (vazia(fila))
    {
        fila->inicio = novo;
    }
    else
    {
        fila->fim->proximo = novo;
    }

    fila->fim = novo;
}

// Função para remover um elemento da fila
double remover(Fila *fila)
{
    if (vazia(fila))
    {
        printf("Erro: Fila vazia!\n");
        exit(1);
    }

    item *aux = fila->inicio;
    double valor = aux->valor;

    fila->inicio = aux->proximo;
    free(aux);

    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    return valor;
}

// Função para mostrar os elementos da fila
void mostrarFila(Fila *fila)
{
    if (vazia(fila))
    {
        printf("Fila vazia!\n");
        return;
    }

    item *aux = fila->inicio;
    while (aux != NULL)
    {
        printf("%.2f ", aux->valor);
        aux = aux->proximo;
    }

    printf("\n");
}