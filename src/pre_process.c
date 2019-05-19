#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pre_process.h"
#include "distance.h"

point_t *read_points( int n ){
  point_t *p = (point_t*)malloc(n*sizeof(point_t));
  if( p == NULL ){
    printf("Malloc error\n");
    exit(0);
  }
  for( int i=0; i<n; i++ ){
    double a, b;
    assert( scanf("%lf %lf", &a, &b) == 2 );
    p[i].x = a;
    p[i].y = b;
  }
  return p;
}

int **pre_process( point_t* p, int n ){
  int **ret = (int**)malloc(n*sizeof(int*));
  if( ret == NULL ){
    printf("Malloc error\n");
    exit(0);
  }
  for( int i=0; i<n; i++ ){
    ret[i] = (int*)malloc(n*sizeof(int));
    if( ret[i] == NULL ){
      printf("Malloc error\n");
      exit(0);
    }
  }
  for( int i=0; i<n; i++ ){
    ret[i][i] = -1;
    for( int j=i+1; j<n; j++ ){
      ret[i][j] = ret[j][i] = distanceEarthKm(p[i].x, p[i].y, p[j].x, p[j].y);
    }
  }
  free(p);
  return ret;
}

edge_t *Matrix_to_array( int **g, int n ){
  edge_t *e = (edge_t*)malloc(n*n*sizeof(edge_t));
  if( e == NULL ){
    printf("Malloc error\n");
    exit(0);
  }
  int it=0;
  for( int i=0; i<n; i++ ){
    for( int j=i+1; j<n; j++ ){
      e[it].w = g[i][j];
      e[it].in = i;
      e[it].out = j;
      it++;
    }
  }
  return e;
}
