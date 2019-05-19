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
  edge_t *e;

  int decision;

  if( argc != 3 ){

    printf("Invalid arguments\n");
    return 0;

  }

  file = fopen(argv[1], "r");

  assert(fscanf(file, "%d", &n) == 1);

  e =(edge_t*)malloc(n*sizeof(edge_t));

  if( e == NULL ){
    printf("Malloc error\n");
    exit(0);
  }

  for( int i=0; i<n; i++ ){
    assert(fscanf(file, "%d", &e[i].w) == 1);
    e[i].in = e[i].out = 1;
  }

  decision = atoi(argv[2]);

  int result;

  switch(decision){
    case 0:
      result = Median(e, n, (n-1)/2);
      break;
    case 1:
      result = quickselect(e, 0, n-1, (n-1)/2);
      break;
  }

  free(e);

  printf("%d\n", result);

  return 0;
}
