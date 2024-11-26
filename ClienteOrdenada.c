// main.c
#include "ListaOrdenada.h"

int main() {
  LISTA lista;
  REGISTRO reg;

  // Inicializar a lista
  inicializarLista(&lista);

  // Exibir lista vazia
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Inserir elementos na lista
  reg.chave = 9;
  inserirElemListaOrd(&lista, reg);
  reg.chave = 3;
  inserirElemListaOrd(&lista, reg);
  reg.chave = 5;
  inserirElemListaOrd(&lista, reg);
  reg.chave = 1;
  inserirElemListaOrd(&lista, reg);
  reg.chave = 13;
  inserirElemListaOrd(&lista, reg);
  for (int j = 0; j <= 120; j+= 2) {
    reg.chave = j;
    inserirElemListaOrd(&lista, reg);
  }

  // Exibir lista após inserções
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Buscar um elemento na lista
  int pos = buscaSequencial(&lista, 5);
  printf("Chave 5 encontrada na posicao: %i do arranjo A.\n", pos);
  
  pos = buscaBinaria(&lista, 5);
  printf("Chave 5 encontrada na posicao: %i do arranjo A.\n", pos);
  
  pos = buscaSentinela(&lista, 5);
  printf("Chave 5 encontrada na posicao: %i do arranjo A.\n", pos);

  // Excluir alguns elementos da lista
  if (excluirElemLista(&lista, 4)) printf("Exclusao bem sucedida: 4.\n");
  if (excluirElemLista(&lista, 8)) printf("Exclusao bem sucedida: 8 (não existe na lista).\n");
  if (excluirElemLista(&lista, 9)) printf("Exclusao bem sucedida: 9.\n");
  for (int k = 0; k <= 120; k+= 2) {
      (excluirElemLista(&lista, k));
  }

  // Exibir lista após exclusões
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Reinicializar a lista
  reinicializarLista(&lista);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  free(lista.A);
  return 0;
}
