#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "fila.h"

int main()
{

    Fila *f;
    int n;
    srand(time(NULL));

    printf("Insira a quantidade de items: ");
    scanf("%d", &n);

    f = criarFila();
    if (!f)
    {
        perror("Não foi possível criar a fila!");
        exit(1);
    }
    printf("Fila vazia ? == '%d'\n", vazia(f));

    for (int i = 0; i < n; i++)
    {
        inserir(f, (rand() % 1000) * 1.234);
    }

    printf("Inserido os elementos\n");
}