#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "quicksort.h"
#include "pre_process.h"
#include "union_find.h"
#include "distance.h"
#include "camerini.h"
#include "median.h"

int main(int argc, char const *argv[]) {
  FILE *cidades;
  int n;
  int **g;

  cidades = fopen(argv[1], "r");
  fscanf(cidades, "%d", &n) ;
  g =(int**)malloc(n*sizeof(int*));
  for( int i=0; i<n; i++ ){
    g[i] = (int*)malloc(n*sizeof(int));
  }

  point_t *p = (point_t*)malloc(n*sizeof(point_t));
  for( int i=0; i<n; i++ ){
    double a, b;
    fscanf(cidades, "%lf %lf", &a, &b) ;
    p[i].x = a;
    p[i].y = b;
  }
  g = pre_process(p, n);

  

  edge_t *e = Matrix_to_array(g, n);
  int result; 
  result = Camerini(e, n);
   
  free(e);
  for( int i=0; i<n; i++ ){
    free(g[i]);
  }
  free(g);

  printf("%d\n", result);

  return 0;
}
