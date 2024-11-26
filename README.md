
# Lista com Redimensionamento Dinâmico
O objetivo da atividade é modificar a implementação de uma lista sequencial
ordenada para que ela suporte o redimensionamento dinâmico.
## Instruções
- Inicializar a lista com 50 elementos de capacidade;
Utilizando a função `resize`;
- Dobrar o tamanho da lista quando a capacidade máxima for atingida;
- Reduzir o tamanho da lista pela metade quando o número de elementos for 25% da capacidade;

## Funcionamento do código modificado
### *Alterações em ListaOrdenada.h*
- `#include <stdlib.h>`
- `REGISTRO *A;` é o ponteiro para o vetor de registros;
- `int tamanho;` define tamanho que será a capacidade atual de elementos;
### *Alterações em ListaOrdenada.c*
- A função *`resize`* recebe o novo tamanho da lista (reduzido ou expandido) e utiliza `realloc` para redimensionar o vetor de forma dinâmica sem modificar seus elementos.
  
Função *`resize`*:
```
void resize(LISTA *l, int novaCapacidade) {
  l->A = (REGISTRO *)realloc(l->A, novaCapacidade * sizeof(REGISTRO));
  if (l->A == NULL) {
    printf("Erro ao redimensionar a lista!\n");
    exit(1);  // Caso haja falha ao redimensionar
  }
  l->tamanho = novaCapacidade;
}
```
- A função *`inicializarLista`* é modificada para que quando inicializada seu tamanho seja 50 e aloca o vetor de registros dinamicamente.
  
Função *`inicializarLista`*:
```
void inicializarLista(LISTA* l){
  l->tamanho = 50;
  l->nroElem = 0;
  l->A = (REGISTRO *)malloc(l->tamanho * sizeof(REGISTRO));
  if (l->A == NULL) {
    printf("Erro ao alocar memória!\n");
    exit(1);
  }
}
```
- A função *`tamanhoEmBytes`* é modificada considerando a alocação dinâmica.
  
Função *`tamanhoEmBytes`*:
```
int tamanhoEmBytes(LISTA* l) {
  return sizeof(LISTA) + l->tamanho * sizeof(REGISTRO);
}
```
- A função *`reinicializarLista`* utiliza a função *`inicializarLista`* para iniciar a lista com capacidade de 50 elementos.
  
Função *`reinicializarLista`*:
```
void reinicializarLista(LISTA* l) {
  l->nroElem = 0;
  inicializarLista(l);
}
```
- A função *`excluirElemListaOrd`* é modificada para que quando a quantidade de elementos for menor ou igual à 25% da capacidade atual, a função *`resize`* seja acessada e o tamanho seja reduzido pela metade. 

Parte modificada da função *`excluirElemListaOrd`*:
```
  if (l->nroElem <= l->tamanho / 4) {
    resize(l, l->tamanho / 2);
  }
```
- A função *`inserirElemListaOrd`* é modificada para que quando a quantidade de elementos for maior ou igual a capacidade máxima, a função *`resize`* seja acessada e o tamanho seja dobrado.

Parte modificada da função *`inserirElemListaOrd`*:
```
  if(l->nroElem >= l->tamanho) {
    resize (l, l->tamanho * 2);
  }
  ```
### *Alteração em ClienteOrdenada.c*
Por conta da inicialização e definição das variáveis e funções em *ListaOrdenada.h* e *ListaOrdenada.c* não foi necessária nenhuma mudança em relação à *ClienteOrdenada.c* para que o redimensionamento dinâmico ocorresse corretamente. Mas para a melhor verficação do funcionamento, as seguintes mudanças foram implementadas:
- Em *`inserirElemListaOrd`* a `reg.chave = 4;` e `reg.chave = 12;` foram substituídos por `reg.chave = 5;` e `reg.chave = 13;` para quando o `for` seja executado e os números pares de 0 a 120 inseridos na lista, a viazualização da exclusão e inserção de números seja mais perceptível.

`for` que insere números pares à lista:
```
  for (int j = 0; j <= 120; j+= 2) {
    reg.chave = j;
    inserirElemListaOrd(&lista, reg);
  }
```
- Por conta da mudança anterior relacionada a substituição dos números pares pelos seus sucessores, as chamadas das funções `buscaSequencial(&lista, 4)`, `buscaBinaria(&lista, 4);` e `buscaSentinela(&lista, 4);` foram modificadas para `buscaSequencial(&lista, 5)`, `buscaBinaria(&lista, 5);` e `buscaSentinela(&lista, 5);`, respectivamente, assim como o número 4 também foi alterado para 5 quando a Chave era encontrada.

- Há a adição de `free(lista.A);`