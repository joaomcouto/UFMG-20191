#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "quicksort.h"
#include "kruskal.h"
#include "union_find.h"

int Kruskal(edge_t *e, int n){
  sort(e, n);
  DSU d;
  DSU_build(&d, n);
  int last=0;
  for( int i=0; i<n; i++ ){
    if( DSU_find(&d, e[i].in) != DSU_find(&d, e[i].out) ){
      DSU_unite(&d, e[i].in, e[i].out);
      last = e[i].w;
    }
  }
  return last;
}
