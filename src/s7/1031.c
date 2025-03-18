#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

int main()
{
    char input[MAX + 1];        // Armazena até 10 caracteres + '\0'
    char temp[MAX + 1] = "";    // Para armazenar a maior sequência de dígitos encontrada
    char longest[MAX + 1] = ""; // Maior sequência de números
    int i = 0, tempIndex = 0, longestLen = 0;

    // Leitura da entrada do usuário
    printf("Digite até 10 caracteres e pressione Enter: ");
    fgets(input, sizeof(input), stdin);

    // Percorre os caracteres lidos
    while (input[i] != '\n' && input[i] != '\0')
    {
        if (isdigit(input[i]))
        { // Se for um número, adiciona à sequência temporária
            temp[tempIndex++] = input[i];
            temp[tempIndex] = '\0';
        }
        else
        {
            // Se a sequência atual for maior que a armazenada, substituímos
            if (tempIndex > longestLen)
            {
                longestLen = tempIndex;
                strcpy(longest, temp);
            }
            tempIndex = 0;  // Reinicia a sequência temporária
            temp[0] = '\0'; // Zera o buffer temporário
        }
        i++;
    }

    // Última verificação para caso a maior sequência esteja no final da string
    if (tempIndex > longestLen)
    {
        strcpy(longest, temp);
    }

    // Exibe o resultado
    if (longestLen > 0)
    {
        printf("Inteiro: %ld\n", strtol(longest, NULL, 10)); // Converte para long e imprime
    }
    else
    {
        printf("Não foi introduzido um inteiro.\n");
    }

    return 0;
}
