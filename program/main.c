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
   
  free(edge);
  for( int i=0; i<n; i++ ){
    free(grafo[i]);
  }
  free(grafo);

  printf("%d\n", result);


  // ANALISE EXPERIMENTAL -----------------===============

/*
n = 9000;
int * tempos = (int *)malloc(1*sizeof(int)) ;
// int tamanhoMaximo = 100 ;

aresta * vetorDeArestas ;
vetorDeArestas = (aresta*) malloc(n*n*sizeof(aresta)) ;
int c = 0;
for( int i=0; i<n ; i++){
  for (int j = i+1 ; j < n ; j++){
    vetorDeArestas[c].peso = (rand()%1000)+1;
    vetorDeArestas[c].oriId = i ;
    vetorDeArestas[c].destId = j ;
    c++;
  }
}
time_t start = clock(); 
Camerini(vetorDeArestas, n);
time_t end = clock(); 
tempos[0] = end-start ;
printf("%d", tempos[0]) ;
free(vetorDeArestas) ;


/*





//for(int k = 5 ; k <= tamanhoMaximo ; k=k+5){
  c= 0 ;
  
  
    
        
        
        
        
  //  }
  
  }
}
*/





//aresta *edge = Matrix_to_array(grafo, n); //edge agora é um vetor de arestas com o id das duas pontas e o peso da aresta
  //int result; 
  //  vertice *p = (vertice*)malloc(n*sizeof(vertice)); 


  //printf("%d\n", end-start) ;


  return 0;
}
