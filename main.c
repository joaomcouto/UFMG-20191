#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#include "testes.h"
#include "grafo.h"


int main(int argc, char const *argv[]) {
  FILE *trilhas ; 
  int numVertices;
  int numArestas ;


  trilhas = fopen(argv[2],"r");
  char * tarefa = argv[1] ;
  fscanf(trilhas,"%d %d", &numVertices, &numArestas) ;



 
  //Verificar que o desempenho da segunda solucao em cima de algum exemplo da primeira pra ver se é no maximo duas vezes pior

  int finalCount = 0 ;

  if (strcmp(tarefa, "tarefa1") == 0){
    graph grafo ;
    grafo.coverage = 0 ;
    grafo.num_arestas = numArestas ;
    grafo.num_vertices = numVertices ;
    grafo.adjlist = malloc(sizeof(node *)*numVertices);
    int i ;
    for(i = 0; i < numVertices ; i++){
      grafo.adjlist[i] = NULL ;
    }

    grafo.visited = malloc(sizeof(int)*numVertices) ;
    for (i = 0 ; i < numVertices ; i++){
      grafo.visited[i] = -1 ; 
    }
  //tarefa1()
  for( i=0; i<numArestas; i++ ){ 
    int a, b;
    fscanf(trilhas, "%d %d", &a, &b) ;
    add_edge(&grafo, a,b) ;
  } 
    dfs(&grafo, 0, 0 ) ;
    for (i = 0 ; i < numVertices ; i++){
      if(grafo.visited[i] == 3)  finalCount++ ;
    }
    printf("%d", finalCount ) ;



  } else if(strcmp(tarefa, "tarefa2") == 0){
      aresta * arestas = malloc(sizeof(aresta) * numArestas) ;
      int a, b, i ;
      for( i=0; i<numArestas; i++ ){ 
        fscanf(trilhas, "%d %d", &a, &b) ;
        arestas[i].oriId = a ;
        arestas[i].destId = b ;
      }
      tarefa2(arestas ,numVertices,numArestas) ;
      

    }
      
    
  

  return 0;
}
