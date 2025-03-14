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

Data data_diff(Data t1, Data t2)
{
    Data res;
    Data maior, menor;

    maior = t1;
    menor = t2;

    if (comparaDatas(t2, t1) == 1)
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

// Função para determinar o século de uma data
int seculoData(Data d)
{
    // O século é obtido dividindo o ano por 100 e acrescentando 1.
    // Exceção:
    // Se o resto da divisão do ano por 100 for 0,
    // o século é apenas o resultado da divisão.
    return ((d.ano % 100) == 0) ? (d.ano / 100) : ((d.ano / 100) + 1);
}

int main()
{

    Data t1 = {18, 1, 2131};
    Data t2 = {1, 4, 1125};

    printf("Comparando datas: t1 e t2 == %d\n", comparaDatas(t1, t2));

    printf("Século de  t1  == %d\n", seculoData(t1));

    Data diff = data_diff(t1, t2);
    printf("A diferença entre t1 e t2 são:\n");
    printf("\t%d anos, %d meses e %d dias\n", diff.ano, diff.mes, diff.dia);
}