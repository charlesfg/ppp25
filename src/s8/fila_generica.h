#ifndef __FILEH__
#define __FILEH__

#include <stdio.h>
#include <stdlib.h>

// Define o `valor` da fila como uma string
#ifndef TYPE
#define TYPE char *
// Informa que o tipo é uma string (não é possível testar o TYPE)
#define TYPE_IS_STRING
//   As linhas acima tem que estar antes da linha a seguir, para
// definir o tipo de dados antes da inclusão
#endif

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
void inserir(Fila *fila, TYPE valor);
TYPE remover(Fila *fila);
void mostrarFila(Fila *fila);
int vazia(Fila *fila);
void destroi(Fila *fila);

#endif