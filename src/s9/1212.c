#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

/**
 * Escreva um programa que, recorrendo a uma pilha,
 * permita apresentar a sequência de números introduzida
 * pelo utilizador, mas por ordem inversa.
 */

int main() {
  pilha_t *s = criaPilha();
  int n = 0;

  printf("Insira uma sequencia de números: -99 para terminar.\n");

  while (n != -99) {
    printf("-> ");
    scanf("%d", &n);
    push(s, (item_t)n);
  }

  printf("Os valores inseridos, em ordem reversa, foram:\n");
  while (!pilhaVazia(s)) {
    printf("%d ,", pop(s));
  }
  free(s);
}