#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializa a semente do gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Gera e imprime 5 números aleatórios entre 0 e RAND_MAX
    printf("Numeros aleatorios entre 0 e %d:\n", RAND_MAX);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }

    // Gera números aleatórios dentro de um intervalo (exemplo: 1 a 100)
    printf("\nNumeros aleatorios entre 1 e 100:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", (rand() % 100) + 1);
    }

    return 0;
}
