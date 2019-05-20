#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "mediana.h"
#include "quicksort.h"

int Mediana(aresta *edge, int esq, int dir){
  return MOM(edge, esq, dir, (esq+dir)/2);
}

int Mediana5(aresta *edge, int esq, int dir){

  int valorMaior=-1, valorSegundoMaior=-1, valorTerceiroMaior=-1;
  int indiceMaior=-1, indiceSegundoMaior=-1, indiceTerceiroMaior =-1;
  for( int i=esq; i<=dir; i++ ){
    if( edge[i].peso > valorMaior ){
      indiceMaior = i;
      valorMaior = edge[i].peso;
    }
  }
  for( int i=esq; i<=dir; i++ ){
    if( i!=indiceMaior && edge[i].peso > valorSegundoMaior ){
      indiceSegundoMaior = i;
      valorSegundoMaior = edge[i].peso;
    }
  }
  for( int i=esq; i<=dir; i++ ){
    if( i!=indiceMaior && i!=indiceSegundoMaior && edge[i].peso > valorTerceiroMaior ){
      indiceTerceiroMaior  = i;
      valorTerceiroMaior = edge[i].peso;
    }
  }
  return indiceTerceiroMaior ;
}

int MOM(aresta *edge, int esq, int dir, int k){

  if( dir-esq+1 <= 5 ){
    quicksort(edge, esq, dir);
    return k;
  }

  int it_m=0;
  aresta *m = (aresta*)malloc(((dir-esq+1)/5)*sizeof(aresta));
  for( int i=esq; i+4<=dir; i+=5 ){
    int mf = Mediana5(edge, i, i+4);
    m[it_m++] = edge[mf];
  }

  int mom = m[MOM(m, 0, it_m-1, (it_m-1)/2)].peso;
  for( int i=esq; i<=dir; i++ ){
    if( edge[i].peso == mom ){
      aresta aux = edge[i];
      edge[i] = edge[dir];
      edge[dir] = aux;
      break;
    }
  }

  free(m);

  int pivot = threeWayPartition(edge, esq, dir);

  if( pivot == k ){
    return pivot;
  }else if( pivot > k ){
    return MOM(edge, esq, pivot-1, k);
  }else{
    return MOM(edge, pivot+1, dir, k);
  }

}
