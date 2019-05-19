#ifndef PRE_PROCESS
#define PRE_PROCESS

#include "constants.h"

typedef struct{
  double x, y;
}vertice;

vertice *read_points( int n );
int **pre_process( vertice* p, int n );
aresta *Matrix_to_array( int **g, int n );

#endif
