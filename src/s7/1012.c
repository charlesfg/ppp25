#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int **gera_matriz(int m, int n)
{

    int **matriz;

    matriz = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)
    {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = rand() % 1000;
        }
    }

    return matriz;
}
int *gera_vetor(int n)
{
    int *vec = (int *)malloc(n * sizeof(int));
    // int *vec = (int *)calloc(n, sizeof(int));
    if (vec == NULL)
    {
        perror("Problema ao alocar a memória");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        vec[i] = rand() % 1000;
    }

    return vec;
}

int maior_dos_ultios_k(int *v, int size, int k)
{
    int maior = 0;

    for (int i = 0; i < k; i++)
    {
        if (v[size - i] > maior)
        {
            maior = v[size - i];
        }
    }
    return maior;
}

int main()
{
    srand(time(NULL));
    int n, k;
    printf("Insira um número para o tamanho do vetor: ");
    scanf("%d", &n);
    printf("Insira um número para o K elementos: (max %d) ", n);
    scanf("%d", &k);

    if (k > n)
    {
        perror("k previsa ser menor que n!");
        exit(1);
    }

    int *v;
    v = gera_vetor(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("O maior dos ultinos K elementos é o '%d'\n",
           maior_dos_ultios_k(v, n, k));
    free(v);
}