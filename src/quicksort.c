#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

void sort( aresta *edge, int n ){
  quicksort(edge, 0, n-1);
}

void get_pivot( aresta *edge, int l, int r ){
  int pivot = (rand()%(r-l+1))+l;
  aresta aux = edge[pivot];
  edge[pivot] = edge[r];
  edge[r] = aux;
}

void quicksort( aresta *edge, int l, int r ){

  if( l >= r ) return;
  get_pivot(edge, l, r);
  int p = threeWayPartition(edge, l, r);
  quicksort(edge, l, p-1);
  quicksort(edge, p+1, r);
}

int threeWayPartition( aresta *edge, int l, int r ){

  int pivot = edge[r].peso;
  int i = l-1;
  aresta aux;

  for( int j=l; j<=r-1; j++ ){
    if( edge[j].peso <= pivot ){
      i++;
      aux = edge[i];
      edge[i] = edge[j];
      edge[j] = aux;
    }
  }

  aux = edge[i+1];
  edge[i+1] = edge[r];
  edge[r] = aux;

  return i+1;
}
