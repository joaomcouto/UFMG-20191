#include <stdio.h>
#include <stdlib.h>

#include "unionFind.h"

void unionFindInit(unionFind *d, int tam){
  d->n = tam;
  d->componentCount= tam;
  d->id = (int*)malloc(d->n*sizeof(int));
  d->size = (int*)malloc(d->n*sizeof(int));
	for( int i=0; i<d->n; i++ ){
		d->id[i] = i;
		d->size[i] = 1;
	}
}

int unionFindFind(unionFind *d, int k){
  if(d->id[k] ==k){ //Se o vertice for de sua propria componente, retorna
    return k ; //A recursao para quando achar o vertice que aponta pra si mesmo
  } else { //Se nao for, acha a componente do vertice para qual o vertice passado aponta
    d->id[k] = unionFindFind(d, d->id[k]) ; //Aproveita para atualizar o componente do vertice passado (otimizacao)
    return d->id[k] ; 
  }
}

void unionFindUnir(unionFind *d, int a, int b){
	a = unionFindFind(d, a); //Dado que a funcao recebeu os IDs dos vertices em suas pontas, acha o componente das duas
	b = unionFindFind(d, b); // ^
  if( a == b ) return; //Se forem do mesmo componente ja tao unidas, retorna
  
	if( d->size[a] > d->size[b] ){  //Se nao forem do mesmo componente
    d->id[b] = a;
	  d->size[a] += d->size[b];
    d->componentCount--;

	} else {
	  d->id[a] = b;
	  d->size[b] += d->size[a];
    d->componentCount--;
  }
}

void unionFindFree(unionFind *d){
  free(d->id);
  free(d->size);
}
