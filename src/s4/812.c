#include <stdio.h>

/*
Considere um vetor de 12 inteiros pré-definido.
Crie uma função que determine a
média desses valores usando apontadores para percorrer o vetor
*/
int v[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

double media_vinteiros(int *v, int n)
{

    double sum = 0.0;          /* total */
    int *ptr;                  /* ponteiro de travessia*/
    int *endptr = v + (n - 1); /* ponteiro para o último elemento*/

    for (ptr = v; ptr <= endptr; ptr++)
        sum += *ptr;

    if (n != 0)
        return sum / n;
    else
        return 0.0;
}

int main()
{
    printf("%lf\n", media_vinteiros(v, 12));
}