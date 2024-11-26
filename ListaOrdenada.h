// listaSequencialOrdenada.h
#ifndef LISTA_SEQUENCIAL_ORDENADA_H
#define LISTA_SEQUENCIAL_ORDENADA_H

#include <stdio.h>
#include <stdlib.h>
#define ERRO -1
#define bool int
#define true 1
#define false 0

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct {
  REGISTRO *A;
  int nroElem;
  int tamanho;
} LISTA;

// Declaração das funções
void resize(LISTA* l, int novaCapacidade);
void inicializarLista(LISTA* l);
void exibirLista(LISTA* l);
int tamanho(LISTA* l);
int tamanhoEmBytes(LISTA* l);
TIPOCHAVE primeiroElem(LISTA* l);
TIPOCHAVE ultimoElem(LISTA* l);
TIPOCHAVE enesimoElem(LISTA* l, int n);
void reinicializarLista(LISTA* l);
int buscaSequencial(LISTA* l, TIPOCHAVE ch);
int buscaSentinela(LISTA* l, TIPOCHAVE ch);
int buscaSentinelaOrdenada(LISTA* l, TIPOCHAVE ch);
int buscaBinaria(LISTA* l, TIPOCHAVE ch);
bool excluirElemLista(LISTA* l, TIPOCHAVE ch);
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);
bool inserirElemListaOrdSemDup(LISTA* l, REGISTRO reg);

#endif // LISTA_SEQUENCIAL_ORDENADA_H
