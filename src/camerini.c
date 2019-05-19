#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "camerini.h"
#include "median.h"
#include "quicksort.h"
#include "union_find.h"
#include "quickselect.h"

int Camerini_sorted(edge_t *e, int n){
  sort(e, (n*(n-1))/2);
  return Bottle_neck_sorted(e, 0, ((n*(n-1))/2)-1, n);
}

int Camerini(edge_t *e, int n){
  return Bottle_neck(e, 0, ((n*(n-1))/2)-1, n);
}

int make_super_node( edge_t *e, DSU *d, int l, int r, int n ){
  int *rep = (int*)malloc(n*sizeof(int));
  if( rep == NULL ){
    printf("Malloc error\n");
    exit(0);
  }

  memset(rep, -1, n*sizeof(int));

  int comp = 0;

  for( int i=0; i<n; i++ ){
    if( rep[DSU_find(d, i)] == -1 ){
      rep[DSU_find(d, i)] = comp++;
    }
  }

  for( int i=l; i<=r; i++ ){
    e[i].in = rep[DSU_find(d, e[i].in)];
    e[i].out = rep[DSU_find(d, e[i].out)];
  }

  free(rep);

  return comp;
}

int Bottle_neck_sorted(edge_t *e, int l, int r, int n){

  if( l == r ){
    return e[l].w;
  }

  int m = (l+r)/2;

  DSU d;
  DSU_build(&d, n);

  for( int i=l; i<=m; i++ ){
    DSU_unite(&d, e[i].in, e[i].out);
  }

  if( d.comp == 1 ){
    DSU_destroy(&d);
    return Bottle_neck(e, l, m, n);
  }else{
    n = make_super_node(e, &d, l, r, n);
    DSU_destroy(&d);
    return Bottle_neck(e, m+1, r, n);
  }

}

int Bottle_neck(edge_t *e, int l, int r, int n){

  if( l == r ){
    return e[l].w;
  }

  int m = Median(e, l, r);

  edge_t aux = e[m];
  e[m] = e[r];
  e[r] = aux;

  m = partition(e, l, r);

  if( m == r ){
    m = (l+r)/2;
  }

  DSU d;
  DSU_build(&d, n);

  for( int i=l; i<=m; i++ ){
    DSU_unite(&d, e[i].in, e[i].out);
  }
  
  if( d.comp == 1 ){
    DSU_destroy(&d);
    return Bottle_neck(e, l, m, n);
  }else{
    n = make_super_node(e, &d, l, r, n);
    DSU_destroy(&d);
    return Bottle_neck(e, m+1, r, n);
  }

}
