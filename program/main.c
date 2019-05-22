#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <time.h>

#include "quicksort.h"
#include "leitura.h"
#include "unionFind.h"
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
  for( int i=0; i<n; i++ ){ //Aloca n ints para para uma das n cidades
    grafo[i] = (int*)malloc(n*sizeof(int)); //Cada posicao das n do grafo tem espaço para n inteiros
  }

  vertice *p = (vertice*)malloc(n*sizeof(vertice)); //Vertices representados por um ponteiro para vertices com n vertices edge suas coordenadas
  for( int i=0; i<n; i++ ){ //Faz leitura das coordenadas das cidades
    double a, b;
    fscanf(cidades, "%lf %lf", &a, &b) ;
    p[i].coordX = a;
    p[i].coordY = b;
  } //No final o vetor p de vertices tem as informacoes de cada cidade
  //O p só é utilizado pra conseguir gerar as distancias na criação da matriz de adjacencia com pesos

  grafo = pre_process(p, n); //grafo é agora uma matriz de adjacencia com os pesos da arestas
  

  aresta *edge = Matrix_to_array(grafo, n); //edge agora é um vetor de arestas com o id das duas pontas e o peso da aresta
  int result; 
  result = Camerini(edge, n);
  for( int i=0; i<n; i++ ){
    free(grafo[i]);
  }
  free(edge);
  free(grafo);
 

  printf("%d\n", result);
  


  return 0;
}
