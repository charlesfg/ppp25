#include <stdio.h>
#include <stdlib.h>
#include "data.h"

// Compara duas datas t1 e t2
int compara_datas(Data t1, Data t2)
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

void gera_datas(Data *vec, int s)
{

    int i;

    for (i = 0; i < s; i++)
    {
        vec[i].ano = rand() % 2000 + 1000;
        vec[i].mes = rand() % 11 + 1;
        vec[i].dia = rand() % 27 + 1;
    }
}

Data data_diff(Data t1, Data t2)
{
    Data res;
    Data maior, menor;

    maior = t1;
    menor = t2;

    if (compara_datas(t2, t1) == 1)
    {
        maior = t2;
        menor = t1;
    }

    res.ano = maior.ano - menor.ano;
    res.mes = maior.mes - menor.mes;
    res.dia = maior.dia - menor.dia;

    if (res.dia < 0)
    {
        res.dia += 30;
        res.mes -= 1;
    }

    if (res.mes < 0)
    {
        res.mes += 12;
        res.ano -= 1;
    }

    return res;
}

void imprimi_datas(Data *vec, int s)
{

    int i;

    for (i = 0; i < s; i++)
    {
        printf("%d/%d/%d\n", vec[i].dia, vec[i].mes, vec[i].ano);
    }
}

// Função para determinar o século de uma data
int seculoData(Data d)
{
    // O século é obtido dividindo o ano por 100 e acrescentando 1.
    // Exceção:
    // Se o resto da divisão do ano por 100 for 0,
    // o século é apenas o resultado da divisão.
    return ((d.ano % 100) == 0) ? (d.ano / 100) : ((d.ano / 100) + 1);
}