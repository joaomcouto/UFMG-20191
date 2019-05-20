#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "mediana.h"
#include "quicksort.h"

int Mediana(aresta *edge, int esq, int dir){
  return MOM(edge, esq, dir, (esq+dir)/2);
}

int Mediana5(aresta *edge, int esq, int dir){

  int m1v=-1, m2v=-1, retv=-1;
  int m1=-1, m2=-1, ret=-1;
  for( int i=esq; i<=dir; i++ ){
    if( edge[i].peso > m1v ){
      m1 = i;
      m1v = edge[i].peso;
    }
  }
  for( int i=esq; i<=dir; i++ ){
    if( i!=m1 && edge[i].peso > m2v ){
      m2 = i;
      m2v = edge[i].peso;
    }
  }
  for( int i=esq; i<=dir; i++ ){
    if( i!=m1 && i!=m2 && edge[i].peso > retv ){
      ret = i;
      retv = edge[i].peso;
    }
  }
  return ret;
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
