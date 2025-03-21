#include "fila_generica.h"
#include <string.h> // para strdup e strcmp
#define MAX_STR 100

int main()
{
    Fila *f = criarFila();
    char buffer[MAX_STR];

    printf("Digite strings (FIM para terminar):\n");

    while (1)
    {
        printf("> ");
        fgets(buffer, MAX_STR, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // remove '\n'

        if (strcmp(buffer, "FIM") == 0)
            break;

        inserir(f, buffer);
    }

    printf("\nStrings inseridas na fila:\n");
    mostrarFila(f);

    destroi(f);
    return 0;
}
