#ifndef PRE_PROCESS
#define PRE_PROCESS

#include "constants.h"

typedef struct{
  double x, y;
}point_t;

point_t *read_points( int n );
int **pre_process( point_t* p, int n );
edge_t *Matrix_to_array( int **g, int n );

#endif
