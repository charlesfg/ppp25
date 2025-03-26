// fila.c
#include <string.h> // para strdup e strcmp
#include "fila_generica.h"

Fila *criarFila()
{
    Fila *f = malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void inserir(Fila *fila, TYPE valor)
{
    item *novo = malloc(sizeof(item));

#ifdef TYPE_IS_STRING
    novo->valor = strdup(valor); // cópia da string
#else
    novo->valor = valor; // tipo simples (int, float, etc)
#endif

    novo->proximo = NULL;

    if (fila->fim == NULL)
    {
        fila->inicio = fila->fim = novo;
    }
    else
    {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

TYPE remover(Fila *fila)
{
    if (fila->inicio == NULL)
    {
#ifdef TYPE_IS_STRING
        return NULL;
#elif defined(TYPE_IS_STRUCT)
        return (TYPE){0};
#else
        return (TYPE)0;
#endif
    }

    item *temp = fila->inicio;
    TYPE valor = temp->valor;

    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(temp);
    return valor;
}

void mostrarFila(Fila *fila)
{
    item *atual = fila->inicio;
    while (atual)
    {
#ifdef TYPE_IS_STRING
        printf("%s\n", atual->valor);
#elif defined(TYPE_IS_INT)
        printf("%d\n", atual->valor);
#elif defined(TYPE_IS_FLOAT)
        printf("%f\n", atual->valor);
#elif defined(TYPE_IS_DOUBLE)
        printf("%lf\n", atual->valor);
#elif defined(TYPE_IS_CHAR)
        printf("%c\n", atual->valor);
#elif defined(TYPE_IS_DATE)
        Data d = atual->valor;
        printf("%d/%d/%d\n", d.dia, d.dia, d.ano);
#else
        printf("Valor genérico\n");
#endif
        atual = atual->proximo;
    }
}

int vazia(Fila *fila)
{
    return fila->inicio == NULL;
}

void destroi(Fila *fila)
{
    while (!vazia(fila))
    {
        __attribute__((unused)) TYPE val = remover(fila);
#ifdef TYPE_IS_STRING
        free(val); // libera string duplicada
#endif
    }
    free(fila);
}
