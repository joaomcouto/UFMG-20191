#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pre_process.h"
#include "distance.h"

vertice *read_points( int n ){
  vertice *p = (vertice*)malloc(n*sizeof(vertice));
  for( int i=0; i<n; i++ ){
    double a, b;
    assert( scanf("%lf %lf", &a, &b) == 2 );
    p[i].x = a;
    p[i].y = b;
  }
  return p;
}

int **pre_process( vertice* p, int n ){
  int **ret = (int**)malloc(n*sizeof(int*));
  for( int i=0; i<n; i++ ){
    ret[i] = (int*)malloc(n*sizeof(int));
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

aresta *Matrix_to_array( int **g, int n ){
  aresta *e = (aresta*)malloc(n*n*sizeof(aresta));
  int it=0;
  for( int i=0; i<n; i++ ){
    for( int j=i+1; j<n; j++ ){
      e[it].peso = g[i][j];
      e[it].oriId = i;
      e[it].destId = j;
      it++;
    }
  }
  return e;
}
