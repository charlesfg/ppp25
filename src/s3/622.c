// 2
// O algoritmo de compressão de dados pode ser conseguido
// por meio da deteção e fusão de dígitos repetidos
// consecutivamente. A título exemplificativo, a
// string “12355555555555542" seria comprimida, resultando a
// string “123c512f42". Tal como se pode verificar,
// o dígito “5”, aparece repetido 12 vezes na string original.
// Deste modo, a sucessão de 12 vezes do dígito 5,
// é comprimida em “c512f”, em que o caracter “c” denota o início da compreensão, o caracter “5” indica que o dígito 5 aparece
// repetido, os caracteres entre “5” e “f” indicam o
// número de vezes que o caracter é repetido (neste caso “12”) e, finalmente, o caracter “f” indica o fim da compressão.
// Pretende-se que desenvolva um programa que peça ao
// utilizador os dados a comprimir (numa string que só
// pode conter algarismos) e escreva no ecrã a sua
// equivalente comprimida. O seu programa deve incluir
// um método compressor que receba uma string não comprimida
// e devolva a sua versão comprimida.
// Nota: A compressão implica a existência de pelo menos
// 4 dígitos: “c”, dígito repetido, número de vezes que
// é repetido e “f”. Assim, só faz sentido efetuar
// compressões em repetições superiores a 4 dígitos.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char comp[100];

char *compress(char *s)
{
    int cnt = 0; // count the repeated strings
    int i = 0;   // to index the arrays
    int f = 0;   // final index
    int j;       // where we will store the results;

    // pointers to mark and count the repeated chars
    char *f, *l;

    for (i = 0; i < strlen(s); i++)
    {
        cnt = 1;
        while (s[j] != '\0' && f[i] == g[i])
        {
            cnt++;
            l++;
        }
        if (cnt > 4)
        {
            j += sprintf(&comp[j], "c%c%d%s", input[i], count, "f");
        }
        else
        {
            while (cnt > 0)
            {
                comp[c_idx++] = s[i];
            }
        }
    }
}

int main()
{
    char str[] = "“12355555555555542";
    printf("string %s: %s\n", str, compress(str));
}