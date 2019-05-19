#include <stdio.h>
#include <stdlib.h>

#include "union_find.h"

void DSU_build(unionFind *d, int tam){
  d->n = tam;
  d->comp= tam;
  d->id = (int*)malloc(d->n*sizeof(int));
  d->size = (int*)malloc(d->n*sizeof(int));
  if( d->id == NULL || d->size == NULL ){
    printf("Malloc error\n");
    exit(0);
  }
	for( int i=0; i<d->n; i++ ){
		d->id[i] = i;
		d->size[i] = 1;
	}
}

int DSU_find(unionFind *d, int k){
	return d->id[k] == k ? k : (d->id[k] = DSU_find(d, d->id[k]));
}

void DSU_unite(unionFind *d, int a, int b){
	a = DSU_find(d, a);
	b = DSU_find(d, b);
  if( a == b ){
    return;
  }
	if( d->size[a] > d->size[b] ){
    int aux = a;
    a = b;
    b = aux;
	}
	d->id[a] = b;
	d->size[b] += d->size[a];
  d->comp--;
}

void DSU_destroy(unionFind *d){
  free(d->id);
  free(d->size);
}
