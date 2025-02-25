#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TAMANHO_MAX 50

// Mapeamento das letras
char original[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cifrado[] =  "DEIABCFGHJKLZYXWVUTSRQPONM";

void codificar(char str[])
{
    int i, j;

    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]); // Converter para maiúscula

        // Percorre a tabela para encontrar substituição
        for (j = 0; j < 26; j++)
        {
            if (str[i] == original[j])
            {
                str[i] = cifrado[j];
                break;
            }
        }
    }
}

void decodificar(char str[])
{
    int i, j;

    for (i = 0; str[i] != '\0'; i++)
    {
        // Percorre a tabela reversamente
        for (j = 0; j < 26; j++)
        {
            if (str[i] == cifrado[j])
            {
                str[i] = original[j];
                break;
            }
        }
    }
}

int main()
{
    char texto[TAMANHO_MAX];

    printf("Digite uma mensagem para codificar: ");
    fgets(texto, TAMANHO_MAX, stdin);
    texto[strcspn(texto, "\n")] = '\0'; // Remover nova linha

    codificar(texto);
    printf("Texto codificado: %s\n", texto);

    decodificar(texto);
    printf("Texto decodificado: %s\n", texto);

    return 0;
}
