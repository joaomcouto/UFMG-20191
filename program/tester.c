#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "quicksort.h"
#include "pre_process.h"
#include "union_find.h"
#include "prim.h"
#include "kruskal.h"
#include "distance.h"
#include "camerini.h"
#include "boruvka.h"
#include "median.h"
#include "quickselect.h"

int main(int argc, char const *argv[]) {

  if( argc != 2 ){
    printf("Invalid arguments\n");
    return 0;
  }

  FILE *file = fopen(argv[1], "r");

  int n;
  assert(fscanf(file, "%d", &n) == 1);

  printf("-> %d\n", n);

  int **g =(int**)malloc(n*sizeof(int*));
  if( g == NULL ){
    printf("Malloc error\n");
    exit(0);
  }
  for( int i=0; i<n; i++ ){
    g[i] = (int*)malloc(n*sizeof(int));
    if( g[i] == NULL ){
      printf("Malloc error\n");
      exit(0);
    }
  }

  for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ ){
      assert(fscanf(file, "%d", &g[i][j]) == 1);
    }
  }

  srand(time(0));

  edge_t *e = Matrix_to_array(g, n);
  int resp_c0 = Camerini(e, n);
  free(e);

  e = Matrix_to_array(g, n);
  free(e);

  e = Matrix_to_array(g, n);
  int resp_k = Kruskal(e, (n*(n-1))/2);
  free(e);

  int resp_p = Prim(g, n);

  int resp_b = Boruvka(g, n);

  for( int i=0; i<n; i++ ){
    free(g[i]);
  }
  free(g);

  printf("%d %d %d %d %d\n", resp_k, resp_p, resp_b, resp_c0);

  if( !(resp_p == resp_c0 && resp_c0 == resp_b && resp_b == resp_k ) ){
    printf("Errooooooooooooooooooooooooooooooooooooooo\n");
    return 1;
  }

  return 0;
}
