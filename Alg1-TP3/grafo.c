#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include "grafo.h"

void add_edge(graph *grafo, int dest, int src){   
	if (dest != src){  
		node *newnode = create_node(dest);
		newnode->next = grafo->adjlist[src];
		grafo->adjlist[src] = newnode;

		newnode = create_node(src);
		newnode->next = grafo->adjlist[dest];
		grafo->adjlist[dest] = newnode;

		grafo->num_arestas++; //com a adicao de uma aresta o numero de arestas do grafo incrementa
	}

}

node *create_node(int dest){  //cria um vertice
	node *vertice = (node *) malloc(sizeof(node));
    vertice->id= dest;
	vertice->next = NULL;
    return vertice;
}


void dfs( graph * grafo, int pai , int filho){
    //Ver se ja foi visitado
    if(grafo->visited[filho] == 1) return; 

    grafo->visited[filho] = 1 ;
    //Verificar se o filho nao tem filhos
    if (grafo->adjlist[filho] == NULL) return;

    node * currentNode ;
    currentNode = grafo->adjlist[filho] ;

    while(currentNode!=NULL){
        if (grafo->visited[currentNode->id] == -1 ){
            dfs(grafo, filho, currentNode->id) ;
        }
        currentNode = currentNode->next ; 
    }

    if (grafo->visited[filho] == 1){
        grafo->visited[pai] = 3;
        grafo->visited[filho] = 2;
    } else {
        grafo->visited[filho] = 3; 
    }

}

void tarefa2(aresta * arestas, int numVertices, int numArestas){
    int a, b, i ;
    int * cobertura = malloc(numVertices* sizeof(int)) ; 
      for (size_t i = 0; i < numVertices; i++){
        cobertura[i] = -1 ; 
      } 
      for(i = 0 ; i < numArestas ; i++){
        a = arestas[i].oriId ;
        b = arestas[i].destId ;
        if (cobertura[a] == -1 && cobertura[b] == -1 ){
          cobertura[a] = 3 ;
          cobertura[b] = 3 ; 
        }
      }
      int finalCount = 0 ;
      for (size_t i = 0; i < numVertices; i++){
        if (cobertura[i]==3 ){
          finalCount++ ;
        }
      } 
      printf("%d", finalCount)  ;
}
