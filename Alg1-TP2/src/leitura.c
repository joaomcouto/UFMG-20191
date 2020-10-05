#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "leitura.h"
#include "distance.h"



int **geraGrafo( vertice* p, int n ){
  int **ret = (int**)malloc(n*sizeof(int*)); 
  for( int i=0; i<n; i++ ){
    ret[i] = (int*)malloc(n*sizeof(int)); //Em cada posição do vetor de ponteiros aloca outra vetor, gerando uma matriz n x n
  }
  for( int i=0; i<n; i++ ){
    ret[i][i] = -1; //Inicializa os pesos da aresta de um vertice pra ele mesmo como -1
    for( int j=i+1; j<n; j++ ){ //Preenche as outras posições com os pesos das arestas
      ret[i][j] = ret[j][i] = distanceEarthKm(p[i].coordX, p[i].coordY, p[j].coordX, p[j].coordY); //Assegura que a aresta de j pra i tem o mesmo peso que i para j
    }
  }
  free(p);
  return ret;
}

aresta *criaVetorArestas( int **g, int n ){ 
  aresta *edge = (aresta*)malloc(n*n*sizeof(aresta)); //n quadrado arestas no total (de cada aresta para todas as outras incluindo ela mesma)
  int it=0;
  for( int i=0; i<n; i++ ){
    for( int j=i+1; j<n; j++ ){
      edge[it].peso = g[i][j];
      edge[it].oriId = i;
      edge[it].destId = j;
      it++;
    }
  }
  return edge;
}
