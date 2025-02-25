#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TAMANHO_MAX 50

// Mapeamento das letras
char original[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cifrado[] = "DEIABCFGHJKLZYXWVUTSRQPONM";

void codificar(char str[])
{
    // Implementar
}

void decodificar(char str[])
{
    // Implmentar
}

int main()
{
    char texto[TAMANHO_MAX];

    printf("Digite uma mensagem para codificar: ");
    // Ler o dado da entrada padrão
    // <- Implementar aqui

    codificar(texto);
    printf("Texto codificado: %s\n", texto);

    decodificar(texto);
    printf("Texto decodificado: %s\n", texto);

    return 0;
}
