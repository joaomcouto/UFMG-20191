#ifndef GRAFO_H
#define GRAFO_H
typedef struct no{
	int id;
	struct no *next;
} node;

typedef struct {
	int coverage;
	int num_vertices;
	int num_arestas;
	node **adjlist;
	int *visited;
} graph;

void add_edge(graph *grafo, int dest, int src) ;

node *create_node(int dest) ;

void dfs( graph * grafo, int pai , int filho) ;

typedef struct{
  int oriId, destId ; 
}aresta ;

#endif