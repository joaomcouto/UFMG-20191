#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "camerini.h"
#include "mediana.h"
#include "quicksort.h"
#include "union_find.h"


int Camerini(aresta *edge, int n){
  return MBST(edge, 0, ((n*(n-1))/2)-1, n);
}

int superVertice( aresta *edge, unionFind *d, int l, int r, int n ){
  int *rep = (int*)malloc(n*sizeof(int));

  memset(rep, -1, n*sizeof(int));

  int comp = 0;

  for( int i=0; i<n; i++ ){
    if( rep[unionFindFind(d, i)] == -1 ){
      rep[unionFindFind(d, i)] = comp++;
    }
  }

  for( int i=l; i<=r; i++ ){
    edge[i].oriId = rep[unionFindFind(d, edge[i].oriId)];
    edge[i].destId = rep[unionFindFind(d, edge[i].destId)];
  }

  free(rep);

  return comp;
}


int MBST(aresta *edge, int l, int r, int n){

  if( l == r ){ //Condicao de parada, ta fazendo in place, tem um array total edge dois indices de onde ta a navegacao, nao precisa alocar mais parada
    return edge[l].peso; //se tem uma aresta ele para, que eh a aresta do botteneck
  }

  int m = Mediana(edge, l, r); //retorna o vetor com a mediana nesse indice m

  aresta aux = edge[m]; //Troca a mediana com o do final
  edge[m] = edge[r];
  edge[r] = aux;

  m = threeWayPartition(edge, l, r);
   // Mediana ta no meio

  if( m == r ){ //Melhora a complexidade quando todos os pesos das arestas foram iguaisb
    m = (l+r)/2;
  }

  unionFind d; //Inicia o union find
  unionFindInit(&d, n); //Inicializa o union find, voce descobre qual conjunto participa edge unir conjuntos 
 // AO inves de matriz de adjancencia rodar DFS edge achar os componentes, faz union find
 //Todos os nos tao no seu component conexo ai pra cada aresta voce junta pra formar um componente conexo
  for( int i=l; i<=m; i++ ){
    unionFindUnir(&d, edge[i].oriId, edge[i].destId);
  }
  // No final tenho um numero de componentes conexas (d.comp)
  
  if( d.comp == 1 ){
    unionFindFree(&d); //Desaloca o union find
    return MBST(edge, l, m, n); //Eh conexo entao a gente entro na condicao que tem que andar pra esquerda (descarta aos maiores que a mediana, manter os nos manter tudo)
  }else{ // Se nao for significa que a menores que a mediana nao sao suiciente pra fazer conexo
    n = superVertice(edge, &d, l, r, n); //Agrupa 
    //N eh o novo numero de nós
    unionFindFree(&d);
    return MBST(edge, m+1, r, n); //Anda pra direita, pega todas maiores que a mediana recursivamente
  }

}

