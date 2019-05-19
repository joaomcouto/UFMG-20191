#include <stdio.h>
#include <stdlib.h>

#include "boruvka.h"
#include "union_find.h"
#include "constants.h"

int Boruvka( int **g, int n ){

  int num_comp = n;
  edge_t *min_edge = (edge_t*)malloc(n*sizeof(edge_t));
  if( min_edge == NULL ){
    printf("Malloc error\n");
    exit(0);
  }
  int mx = -1;

  DSU d;
  DSU_build(&d, n);

  while( num_comp > 1 ){

    for( int i=0; i<n; i++ ){
      min_edge[i].out = min_edge[i].in = -1;
      min_edge[i].w = INF;
    }

    for( int i=0; i<n; i++ ){
      for( int j=i+1; j<n; j++ ){
        int a = DSU_find(&d, i);
        int b = DSU_find(&d, j);
        if( a == b ) continue;
        if( min_edge[a].w > g[i][j] ){
          min_edge[a].w = g[i][j];
          min_edge[a].in = a;
          min_edge[a].out = b;
        }
        if( min_edge[b].w > g[i][j] ){
          min_edge[b].w = g[i][j];
          min_edge[b].in = b;
          min_edge[b].out = a;
        }
      }
    }

    for( int i=0; i<n; i++ ){
      if( min_edge[i].in == -1 || min_edge[i].out == -1 ) continue;
      int a = DSU_find(&d, min_edge[i].in);
      int b = DSU_find(&d, min_edge[i].out);
      if( a == b ) continue;
      if( mx < min_edge[i].w ){
        mx = min_edge[i].w;
      }
      num_comp--;
      DSU_unite(&d, a, b);
    }

  }

  free(min_edge);
  DSU_destroy(&d);

  return mx;
}
