#include <stdio.h>
#include <string.h>

void remove_espacos(char str[])
{
    // i percorre a string, j guarda a posição do próximo caractere válido
    int i, j = 0; 

    for (i = 0; str[i] != '\0'; i++)
    { // Percorre a string até o final
        if (str[i] != ' ')
        {  // Se o caractere não for espaço                  
            str[j] = str[i]; // Copia o caractere para a posição j
            j++;             // Vai para o próximo caractere válido
        }
    }
    // Adiciona o caractere nulo para indicar o fim da nova string
    str[j] = '\0'; 
}

int main()
{
    // Declara uma string de tamanho 100 
    char frase[100]; 

    printf("Digite uma frase: ");
    // Lê a string do usuário, incluindo espaços
    fgets(frase, sizeof(frase), stdin); 

    // Remover o caractere de nova linha '\n' que fgets pode incluir
    frase[strcspn(frase, "\n")] = '\0';

     // Chama a função para remover os espaços
    remove_espacos(frase);
    // Exibe a frase sem espaços                   
    printf("Frase sem espaços: '%s'\n", frase); 

    return 0;
}
