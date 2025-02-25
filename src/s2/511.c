#include <stdio.h>

// Função que substitui os números ímpares pelo seu dobro
void substituir_impares(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 != 0) { // Se for ímpar
            vetor[i] *= 2; // Substitui pelo dobro
        }
    }
}

int main() {
    int tamanho;
    
    // Lendo o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    int vetor[tamanho];
    
    // Lendo os elementos do vetor
    printf("Digite os %d elementos do vetor: ", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    
    // Chamando a função para substituir os ímpares
    substituir_impares(vetor, tamanho);
    
    // Exibindo o vetor transformado
    printf("Vetor transformado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}
