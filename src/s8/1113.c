#include "fila_generica.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "data.h"
#include "utils.h"

Data retorna_maior_data(Fila *f)
{
    Data maior = {0, 0, 0};
    item *tmp;

    if (vazia(f))
    {
        printf("Fila vazia!!");
        return maior;
    }

    tmp = f->inicio;
    while (tmp != f->fim)
    {
        if (compara_datas(tmp->valor, maior))
        {
            maior = tmp->valor;
        }
        tmp = tmp->proximo;
    }
    return maior;
}

int main()
{

    int n = 20;
    Data *v = (Data *)malloc(sizeof(Data) * n);
    gera_datas(v, n);

    Fila *f = criarFila();

    for (int i = 0; i < n; i++)
    {
        inserir(f, v[i]);
    }

    printf("Datas inseridas no vetor!");
    mostrarFila(f);

    printf("A maior data da lista é:");
    Data d = retorna_maior_data(f);
    printf("%d/%d/%d\n", d.dia, d.dia, d.ano);

    return 0;
}