#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "camerini.h"
#include "mediana.h"
#include "quicksort.h"
#include "unionFind.h"


int Camerini(aresta *edge, int n){
  return MBST(edge, 0, ((n*(n-1))/2)-1, n); //A chama da MBST eh posicional.. porque/como n*n-1)/2 quando temos n2 arestas
}

int superVertice( aresta *edge, unionFind *d, int esq, int dir, int n ){
  int *rep = (int*)malloc(n*sizeof(int));

  memset(rep, -1, n*sizeof(int));

  int comp = 0;

  for( int i=0; i<n; i++ ){
    if( rep[unionFindFind(d, i)] == -1 ){
      rep[unionFindFind(d, i)] = comp++;
    }
  }

  for( int i=esq; i<=dir; i++ ){
    edge[i].oriId = rep[unionFindFind(d, edge[i].oriId)];
    edge[i].destId = rep[unionFindFind(d, edge[i].destId)];
  }

  free(rep);

  return comp;
}


int MBST(aresta *edge, int esq, int dir, int n){

  if( esq == dir ){ //Condicao de parada, ta fazendo in place, tem um array total edge dois indices de onde ta a navegacao, nao precisa alocar mais parada
    return edge[esq].peso; //se tem uma aresta ele para, que eh a aresta do botteneck
  }

  int m = Mediana(edge, esq, dir); //m é a posicao da mediana no vetor de arestas

//Coloca a mediana na posição final pra fazer particionamento 3-way
  aresta aux = edge[m]; 
  edge[m] = edge[dir];
  edge[dir] = aux;

  m = threeWayPartition(edge, esq, dir);
   // Agora o subvetor está particionado com a mediana no meio
   // m é o indice em que se encontra a mediana

  if( m == dir ){ //Melhora a complexidade quando todos os pesos das arestas foram iguais (???)
    m = (esq+dir)/2;
  }

  unionFind d; //Cria uma struct union find, que guarda o número de vertices, o id da componente de cada, o tamanho de cada componente e o número de componentes
  unionFindInit(&d, n); //Inicializa o union find com cada vertice em sua propria componente, tamanhos = 1 e numero de componentes como o numero de vertices
 // AO inves de matriz de adjancencia rodar DFS edge achar os componentes, faz union find

  for( int i=esq; i<=m; i++ ){ //Para cada aresta menor que a mediana
    unionFindUnir(&d, edge[i].oriId, edge[i].destId); //Faz union na estrutura union find pras arestas menores que a mediana
  }
  // No final tenho um numero de componentes conexas (d.componentCount)
  
  if( d.componentCount == 1 ){
    unionFindFree(&d); //Desaloca o union find
    return MBST(edge, esq, m, n); //Eh conexo entao a gente entro na condicao que tem que andar pra esquerda (descarta aos maiores que a mediana, manter os nos manter tudo)
  }else{ // Se nao for significa que a menores que a mediana nao sao suiciente pra fazer conexo
    n = superVertice(edge, &d, esq, dir, n); //Agrupa 
    //N eh o novo numero de nós
    unionFindFree(&d);
    return MBST(edge, m+1, dir, n); //Anda pra direita, pega todas maiores que a mediana recursivamente
  }

}

