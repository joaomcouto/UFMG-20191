#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pre_process.h"

int main(int argc, char const *argv[]) {

  if( argc != 2 ){
    printf("Invalid arguments\n");
    return 0;
  }

  FILE *file_in = fopen(argv[1], "r");
  FILE *file_out = fopen("graph.txt", "w");

  int n;
  assert( fscanf(file_in, "%d", &n) == 1 );

  point_t *p = (point_t*)malloc(n*sizeof(point_t));
  if( p == NULL ){
    printf("Malloc error\n");
    exit(0);
  }
  for( int i=0; i<n; i++ ){
    double a, b;
    assert( fscanf(file_in, "%lf %lf", &a, &b) == 2 );
    p[i].x = a;
    p[i].y = b;
  }

  int **g = pre_process(p, n);

  fprintf(file_out, "%d\n", n);

  for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ ){
      fprintf(file_out, "%d ", g[i][j]);
    }
    fprintf(file_out, "\n");
  }

  for( int i=0; i<n; i++ ){
    free(g[i]);
  }
  free(g);

  return 0;
}
