#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

void sort( edge_t *e, int n ){
  quicksort(e, 0, n-1);
}

void get_pivot( edge_t *e, int l, int r ){
  int pivot = (rand()%(r-l+1))+l;
  edge_t aux = e[pivot];
  e[pivot] = e[r];
  e[r] = aux;
}

void quicksort( edge_t *e, int l, int r ){

  if( l >= r ) return;
  get_pivot(e, l, r);
  int p = partition(e, l, r);
  quicksort(e, l, p-1);
  quicksort(e, p+1, r);
}

int partition( edge_t *e, int l, int r ){

  int pivot = e[r].w;
  int i = l-1;
  edge_t aux;

  for( int j=l; j<=r-1; j++ ){
    if( e[j].w <= pivot ){
      i++;
      aux = e[i];
      e[i] = e[j];
      e[j] = aux;
    }
  }

  aux = e[i+1];
  e[i+1] = e[r];
  e[r] = aux;

  return i+1;
}
