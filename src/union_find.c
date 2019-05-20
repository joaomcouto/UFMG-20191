#include <stdio.h>
#include <stdlib.h>

#include "union_find.h"

void unionFindInit(unionFind *d, int tam){
  d->n = tam;
  d->comp= tam;
  d->id = (int*)malloc(d->n*sizeof(int));
  d->size = (int*)malloc(d->n*sizeof(int));
	for( int i=0; i<d->n; i++ ){
		d->id[i] = i;
		d->size[i] = 1;
	}
}

int unionFindFind(unionFind *d, int k){
	return d->id[k] == k ? k : (d->id[k] = unionFindFind(d, d->id[k]));
}

void unionFindUnir(unionFind *d, int a, int b){
	a = unionFindFind(d, a);
	b = unionFindFind(d, b);
  if( a == b ) return;
  
	if( d->size[a] > d->size[b] ){
    int aux = a;
    a = b;
    b = aux;
	}
	d->id[a] = b;
	d->size[b] += d->size[a];
  d->comp--;
}

void unionFindFree(unionFind *d){
  free(d->id);
  free(d->size);
}
