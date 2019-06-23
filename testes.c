#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <time.h>
#include "grafo.h"

void testeLeitura(graph *grafo, int numVertices){
  node * currentNode ;
  for ( int i = 0 ; i < numVertices ; i++){
    currentNode = grafo->adjlist[i] ;
    while(currentNode != NULL){
      printf("%d " , currentNode->id);
    currentNode = currentNode->next ; 
    }
    printf("\n") ;
  }
}