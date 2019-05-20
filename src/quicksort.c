#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

void sort( aresta *edge, int n ){
  quicksort(edge, 0, n-1);
}

void get_pivot( aresta *edge, int esq, int dir ){
  int pivot = (rand()%(dir-esq+1))+esq;
  aresta aux = edge[pivot];
  edge[pivot] = edge[dir];
  edge[dir] = aux;
}

void quicksort( aresta *edge, int esq, int dir ){

  if( esq >= dir ) return;
  get_pivot(edge, esq, dir);
  int p = threeWayPartition(edge, esq, dir);
  quicksort(edge, esq, p-1);
  quicksort(edge, p+1, dir);
}

int threeWayPartition( aresta *edge, int esq, int dir ){

  int pivot = edge[dir].peso;
  int i = esq-1;
  aresta aux;

  for( int j=esq; j<=dir-1; j++ ){
    if( edge[j].peso <= pivot ){
      i++;
      aux = edge[i];
      edge[i] = edge[j];
      edge[j] = aux;
    }
  }

  aux = edge[i+1];
  edge[i+1] = edge[dir];
  edge[dir] = aux;

  return i+1;
}
