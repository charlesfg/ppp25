#ifndef __DATA_H__ASASDADASDAS
#define __DATA_H__ASASDADASDAS

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

int compara_datas(Data t1, Data t2);
void gera_datas(Data *vec, int s);
void imprimi_datas(Data *vec, int s);
int seculoData(Data d);
Data data_diff(Data t1, Data t2);

#endif