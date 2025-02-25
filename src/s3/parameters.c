#include <stdio.h>

// IGNOREM ISSO ---------------------------------------
#define PRINT_INFO(var)                                                                 \
    printf("[ %02d | %23s]:%10s| addr: %p | ", __LINE__, __func__, #var, (void *)&var); \
    printf("%d\n", var);

// Função que recebe um número por valor

char line[] = "----------------------------------";

void alterar_por_valor(int x)
{

    printf("-- alterar_por_valor()      %s\n", line);
    PRINT_INFO(x);
    x = 100; // Modifica apenas a cópia de x
    PRINT_INFO(x);
    printf("-- END %s\n", line);
}

// Função que recebe um número por referência (ponteiro)
void alterar_por_referencia(int *x)
{
    printf("-- alterar_por_referencia() %s\n", line);
    PRINT_INFO(*x);
    *x = 100; // Modifica o valor na memória original
    PRINT_INFO(*x);
    printf("-- END %s\n", line);
}

// Função que altera um vetor (arrays são passados por referência)
void alterar_vetor(int v[])
{

    printf("-- alterar_vetor()          %s\n", line);
    // PRINT_INFO(v);
    PRINT_INFO(v[0]);
    v[0] = 100; // Modifica diretamente o primeiro elemento do vetor
    PRINT_INFO(v[0]);
    printf("-- END %s\n", line);
}

int main()
{
    int a = 10;               // Variável simples
    int b = 10;               // Variável que será usada com referência
    int vetor[3] = {1, 2, 3}; // Vetor de inteiros

    printf("-- main()                   %s\n", line);
    PRINT_INFO(a);
    alterar_por_valor(a);
    PRINT_INFO(a);

    PRINT_INFO(b);
    alterar_por_referencia(&b);
    PRINT_INFO(b);

    // PRINT_INFO(vetor);
    PRINT_INFO(vetor[0]);
    alterar_vetor(vetor);
    PRINT_INFO(vetor[0]);
    printf("-- END main() %s\n", line);
    return 0;
}
