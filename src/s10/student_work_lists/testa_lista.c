#include <stdio.h>
#include <string.h>

#include "lista.h"

int main() {
  printf("== INICIANDO TESTES DA LISTA ==\n");

  struct list_node *lista = create();
  if (empty(lista)) {
    printf("[OK] Lista criada está vazia\n");
  } else {
    printf("[ERRO] Lista criada não está vazia\n");
  }

  struct person p1 = {"Ana", 20};
  struct person p2 = {"Bruno", 22};
  struct person p3 = {"Carla", 19};

  insert(lista, p1);
  insert(lista, p2);
  insert(lista, p3);

  printf("\n[INFO] Lista após inserções:\n");
  print(lista);

  struct list_node *prev = NULL;
  struct list_node *curr = NULL;

  search(lista, "Bruno", &prev, &curr);
  if (curr != NULL && strcmp(curr->per.name, "Bruno") == 0) {
    printf("[OK] Encontrado Bruno na lista\n");
  } else {
    printf("[ERRO] Bruno não encontrado na lista\n");
  }

  delete (lista, "Ana");
  printf("\n[INFO] Lista após remover Ana:\n");
  print(lista);

  lista = clean(lista);
  if (lista == NULL) {
    printf("[OK] Lista esvaziada com sucesso\n");
  } else {
    printf("[ERRO] Lista ainda contém elementos após limpeza\n");
  }

  return 0;
}
