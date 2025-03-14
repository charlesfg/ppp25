#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include "data.h"

int main()
{

    Data t1 = {18, 1, 2131};
    Data t2 = {1, 4, 1125};

    printf("Comparando datas: t1 e t2 == %d\n", compara_datas(t1, t2));

    printf("Século de  t1  == %d\n", seculoData(t1));

    Data diff = data_diff(t1, t2);
    printf("A diferença entre t1 e t2 são:\n");
    printf("\t%d anos, %d meses e %d dias\n", diff.ano, diff.mes, diff.dia);
}