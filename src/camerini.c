#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "camerini.h"
#include "mediana.h"
#include "quicksort.h"
#include "union_find.h"


int Camerini(aresta *e, int n){
  return MBST(e, 0, ((n*(n-1))/2)-1, n);
}

int superVertice( aresta *e, unionFind *d, int l, int r, int n ){
  int *rep = (int*)malloc(n*sizeof(int));

  memset(rep, -1, n*sizeof(int));

  int comp = 0;

  for( int i=0; i<n; i++ ){
    if( rep[unionFindFind(d, i)] == -1 ){
      rep[unionFindFind(d, i)] = comp++;
    }
  }

  for( int i=l; i<=r; i++ ){
    e[i].oriId = rep[unionFindFind(d, e[i].oriId)];
    e[i].destId = rep[unionFindFind(d, e[i].destId)];
  }

  free(rep);

  return comp;
}


int MBST(aresta *e, int l, int r, int n){

  if( l == r ){ //Condicao de parada, ta fazendo in place, tem um array total e dois indices de onde ta a navegacao, nao precisa alocar mais parada
    return e[l].peso; //se tem uma aresta ele para, que eh a aresta do botteneck
  }

  int m = Mediana(e, l, r); //retorna o vetor com a mediana nesse indice m

  aresta aux = e[m]; //Troca a mediana com o do final
  e[m] = e[r];
  e[r] = aux;

  m = threeWayPartition(e, l, r);
   // Mediana ta no meio

  if( m == r ){ //Melhora a complexidade quando todos os pesos das arestas foram iguaisb
    m = (l+r)/2;
  }

  unionFind d; //Inicia o union find
  unionFindInit(&d, n); //Inicializa o union find, voce descobre qual conjunto participa e unir conjuntos 
 // AO inves de matriz de adjancencia rodar DFS e achar os componentes, faz union find
 //Todos os nos tao no seu component conexo ai pra cada aresta voce junta pra formar um componente conexo
  for( int i=l; i<=m; i++ ){
    unionFindUnir(&d, e[i].oriId, e[i].destId);
  }
  // No final tenho um numero de componentes conexas (d.comp)
  
  if( d.comp == 1 ){
    unionFindFree(&d); //Desaloca o union find
    return MBST(e, l, m, n); //Eh conexo entao a gente entro na condicao que tem que andar pra esquerda (descarta aos maiores que a mediana, manter os nos manter tudo)
  }else{ // Se nao for significa que a menores que a mediana nao sao suiciente pra fazer conexo
    n = superVertice(e, &d, l, r, n); //Agrupa 
    //N eh o novo numero de nós
    unionFindFree(&d);
    return MBST(e, m+1, r, n); //Anda pra direita, pega todas maiores que a mediana recursivamente
  }

}
//Uniond find e cameriri, o threeWayPartition ta no quicksort.c, unionfind todo e threeWayPartition do quicksort e o da mediana
//Mediana.c, camerini.c, quicksort.c
//mediana usa partitio e o quicksort
//Pega elas e criar uma main e fazer do zero e usar esses role pra resolver
