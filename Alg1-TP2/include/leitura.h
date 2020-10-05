#ifndef LEITURA_H
#define LEITURA_H

#include "auxiliar.h"

typedef struct{
  double coordX, coordY;
}vertice;

int **geraGrafo( vertice* p, int n );
aresta *criaVetorArestas( int **g, int n );

#endif
