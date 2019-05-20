#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "quicksort.h"
#include "leitura.h"
#include "union_find.h"
#include "distance.h"
#include "camerini.h"
#include "mediana.h"

int main(int argc, char const *argv[]) {
  FILE *cidades;
  int n;
  int **grafo;

  cidades = fopen(argv[1],"r");
  fscanf(cidades,"%d", &n) ;
  grafo =(int**)malloc(n*sizeof(int*)); //Grafo com n cidades representado como um ponteiro para ponteiros de inteiro
  for( int i=0; i<n; i++ ){
    grafo[i] = (int*)malloc(n*sizeof(int)); //Cada posicao do grafo tem n posicoes com inteiros
  }

  vertice *p = (vertice*)malloc(n*sizeof(vertice)); //Vertices representados por um ponteiro para vertices com n vertices edge suas coordenadas
  for( int i=0; i<n; i++ ){
    double a, b;
    fscanf(cidades, "%lf %lf", &a, &b) ;
    p[i].coordX = a;
    p[i].coordY = b;
  }
  grafo = pre_process(p, n);

  

  aresta *edge = Matrix_to_array(grafo, n);
  int result; 
  result = Camerini(edge, n);
   
  free(edge);
  for( int i=0; i<n; i++ ){
    free(grafo[i]);
  }
  free(grafo);

  printf("%d\n", result);

  return 0;
}
