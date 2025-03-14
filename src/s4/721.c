#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

// Compara duas datas t1 e t2
int comparaDatas(Data t1, Data t2)
{

    if (t1.ano == t2.ano)
    {
        if (t1.mes == t2.mes)
        {
            if (t1.dia == t2.dia)
            {
                return 0;
            }
            else if (t1.dia > t2.dia)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (t1.mes > t2.mes)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if (t1.ano > t2.ano)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void generate_datas(Data *vec, int s)
{

    int i;

    for (i = 0; i < s; i++)
    {
        vec[i].ano = rand() % 2000 + 1000;
        vec[i].mes = rand() % 11 + 1;
        vec[i].dia = rand() % 27 + 1;
    }
}

void print_data(Data vec[], int s)
{

    int i;

    for (i = 0; i < s; i++)
    {
        printf("%d/%d/%d\n", vec[i].dia, vec[i].mes, vec[i].ano);
    }
}

int main()
{

    Data v[4] = {
        {11, 1, 2131},
        {12, 4, 1125},
        {13, 4, 1125},
        {15, 4, 1125},
    };

    // generate_datas(&v, 10);

    print_data(v, 4);
}