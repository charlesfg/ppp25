#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void utils_init()
{
    // can be used to initialize dependent function
    srand(time(NULL));
}

int *gera_vetor_int(int n)
{
    int *vec = NULL;
    vec = (int *)malloc(n * sizeof(int));

    return vec;
}

void rand_values_to_vec(int *v, int n)
{
    for (int i = 0; i < n; i++)
        v[i] = rand() % 1000;
}