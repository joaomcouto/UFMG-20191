#ifndef LEITURA_H
#define LEITURA_H

#include "auxiliar.h"

typedef struct{
  double coordX, coordY;
}vertice;

int **pre_process( vertice* p, int n );
aresta *Matrix_to_array( int **g, int n );

#endif
