#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

void sort( aresta *edge, int n ){
  quicksort(edge, 0, n-1);
}

void geraPivot( aresta *edge, int esq, int dir ){
  int pivot = (rand()%(dir-esq+1))+esq;
  aresta aux = edge[pivot];
  edge[pivot] = edge[dir];
  edge[dir] = aux;
}

void quicksort( aresta *edge, int esq, int dir ){

  if( esq >= dir ) return;
  geraPivot(edge, esq, dir);
  int p = threeWayPartition(edge, esq, dir);
  quicksort(edge, esq, p-1);
  quicksort(edge, p+1, dir);
}

int threeWayPartition( aresta *edge, int esq, int dir ){ //Usa a premissa de que o pivot a ser utilizado já ta na ultima posição

  int pivot = edge[dir].peso;
  int i = esq-1;
  aresta aux;

  for( int j=esq; j<=dir-1; j++ ){ //Avalia cada posicao do subvetor,da esquerda pra direita, uma a uma
    if( edge[j].peso <= pivot ){ //Se for menor que o pivot, cresce o limite superior da partição de menores
      i++; //i representa o limite superior do conjunto de elementos menores que o pivot
      aux = edge[i]; //Originalment esse i é o primeiro elemento da partição de elementos maiores, passando ele pro fundo (pos j), ele continua dentro da partição certa
      edge[i] = edge[j]; //Agora a posição i (limite inferior da particao menor) tem o novo elemento, que é menor que o pivot
      edge[j] = aux; //Agora a posição j tem o elemento que era o primeiro elemento na partição de elementos maiores
    }
  }

  aux = edge[i+1]; //Ao final, colocamos o pivot na posição central entre as duas partições
  edge[i+1] = edge[dir]; //Fazemos isso trocando o primeiro elemento maior que o pivot, com o pivot.
  edge[dir] = aux;

  return i+1; //Retorna o indice do pivot
}
