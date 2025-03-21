#include "fila_generica.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

#define MAX_STR 100

void insere_na_fila(int *v, int n, Fila *f)
{
    for (int i = 0; i < n; i++)
        inserir(f, v[i]);
}

int main()
{
    Fila *f = criarFila();
    int n;
    int *vec;

    srand(time(NULL));

    printf("Digite  o tamanho de n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        perror("n must be >= 0! Exiting ...\n");
        exit(1);
    }

    vec = gera_vetor_int(n);
    rand_values_to_vec(vec, n);

    insere_na_fila(vec, n, f);

    mostrarFila(f);

    destroi(f);
    return 0;
}
