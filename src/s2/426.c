#include <stdio.h>

int inverte(int i) {
    int invertido = 0;
    while (i > 0) {
        invertido = invertido * 10 + (i % 10);
        i /= 10;
    }
    return invertido;
}

int eh_capicua(int n) {
    return n == inverte(n);
}

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Números negativos não são considerados capicuas.\n");
    } else if (eh_capicua(numero)) {
        printf("%d é um número capicua.\n", numero);
    } else {
        printf("%d não é um número capicua.\n", numero);
    }

    return 0;
}
