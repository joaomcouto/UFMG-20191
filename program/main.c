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

  FILE *file;
  int n;
  int **g;

  int decision;

  if( argc == 2 ){

    file = fopen(argv[1], "r");

    assert(fscanf(file, "%d", &n) == 1);

    g =(int**)malloc(n*sizeof(int*));
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

    point_t *p = (point_t*)malloc(n*sizeof(point_t));
    if( p == NULL ){
      printf("Malloc error\n");
      exit(0);
    }
    for( int i=0; i<n; i++ ){
      double a, b;
      assert( fscanf(file, "%lf %lf", &a, &b) == 2 );
      p[i].x = a;
      p[i].y = b;
    }

    g = pre_process(p, n);

    decision = 0;

  }else if( argc == 3 ){

    file = fopen(argv[1], "r");

    assert(fscanf(file, "%d", &n) == 1);

    g =(int**)malloc(n*sizeof(int*));
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

    decision = atoi(argv[2]);

  }else{
    printf("Invalid arguments\n");
    return 0;
  }

  edge_t *e = Matrix_to_array(g, n);
  int result;

  switch(decision){
    case 0:
      result = Camerini(e, n);
      break;
    case 1:
      result = Camerini_sorted(e, n);
      break;
    case 2:
      result = Kruskal(e, (n*(n-1))/2);
      break;
    case 3:
      result = Prim(g, n);
      break;
    case 4:
      result = Boruvka(g, n);
      break;
  }

  free(e);
  for( int i=0; i<n; i++ ){
    free(g[i]);
  }
  free(g);

  printf("%d\n", result);

  return 0;
}
