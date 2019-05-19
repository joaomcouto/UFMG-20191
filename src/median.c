#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "median.h"
#include "quicksort.h"

int Median(aresta *e, int l, int r){
  return Median_of_median(e, l, r, (l+r)/2);
}

int Median_of_five(aresta *e, int l, int r){

  int m1v=-1, m2v=-1, retv=-1;
  int m1=-1, m2=-1, ret=-1;
  for( int i=l; i<=r; i++ ){
    if( e[i].w > m1v ){
      m1 = i;
      m1v = e[i].w;
    }
  }
  for( int i=l; i<=r; i++ ){
    if( i!=m1 && e[i].w > m2v ){
      m2 = i;
      m2v = e[i].w;
    }
  }
  for( int i=l; i<=r; i++ ){
    if( i!=m1 && i!=m2 && e[i].w > retv ){
      ret = i;
      retv = e[i].w;
    }
  }
  return ret;
}

int Median_of_median(aresta *e, int l, int r, int k){

  if( r-l+1 <= 5 ){
    quicksort(e, l, r);
    return k;
  }

  int it_m=0;
  aresta *m = (aresta*)malloc(((r-l+1)/5)*sizeof(aresta));
  if( m == NULL ){
    printf("Malloc error\n");
    exit(0);
  }
  for( int i=l; i+4<=r; i+=5 ){
    int mf = Median_of_five(e, i, i+4);
    m[it_m++] = e[mf];
  }

  int mom = m[Median_of_median(m, 0, it_m-1, (it_m-1)/2)].w;
  for( int i=l; i<=r; i++ ){
    if( e[i].w == mom ){
      aresta aux = e[i];
      e[i] = e[r];
      e[r] = aux;
      break;
    }
  }

  free(m);

  int pivot = partition(e, l, r);

  if( pivot == k ){
    return pivot;
  }else if( pivot > k ){
    return Median_of_median(e, l, pivot-1, k);
  }else{
    return Median_of_median(e, pivot+1, r, k);
  }

}
