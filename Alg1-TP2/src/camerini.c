#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#include "camerini.h"
#include "mediana.h"
#include "quicksort.h"
#include "unionFind.h"


int Camerini(aresta *edge, int n){
  return MBST(edge, 0, ((n*(n-1))/2)-1, n); //A chama da MBST eh posicional em relação ao vetor de arestas
}

void superVertice( aresta *edge, unionFind *d, int esq, int dir, int n ){ //n = numero de vertices do subvetor que chamou o super vertice
  int *rep = (int*)malloc(n*sizeof(int)); 
  //Pra cada representante de cada componente conexo atribuir um inindice de 0 a n-1
  int i ; 
  for(i = 0 ; i < n ; i ++ ) rep[i] = - 1 ;


  int comp = 0;

  for( int i=0; i<n; i++ ){ //Itera entre todos os vertices 
    if( rep[unionFindFind(d, i)] == -1 ){ // E pra cada um ve se seu representante ainda está não inicializado em rep
      rep[unionFindFind(d, i)] = comp++; 
    }
  }
  //No rep os representantes de componentes vao ter o indice no novo grafo com os super vertices
  //A ideia é que agora o que importa são as arestas maiores que a mediana, então o valor delas em rep não importa
  //A ideia é que em rep temos então os indices das novas arestas (super arestas)

  for( int i=esq; i<=dir; i++ ){ //Muda os índices das arestas para refletirem o novo grafo (com os super vertices)
    edge[i].oriId = rep[unionFindFind(d, edge[i].oriId)];
    edge[i].destId = rep[unionFindFind(d, edge[i].destId)];
  }
//Agora as arestas tem como vertices numeros entre 0 e n-1 que sao os indices das componentes componexas
  free(rep);

}


int MBST(aresta *edge, int esq, int dir, int n){

  if( esq == dir ){ 
    return edge[esq].peso; //se tem uma aresta ele para, é a bottleneck
  }

  int m = Mediana(edge, esq, dir); //m é a posicao da mediana no vetor de arestas
  

//Coloca a mediana na posição final pra fazer particionamento 3-way
  aresta aux = edge[m]; 
  edge[m] = edge[dir];
  edge[dir] = aux;
  

  m = threeWayPartition(edge, esq, dir);
   // Agora o subvetor está particionado com a mediana no meio
   // m é o indice em que se encontra a mediana

  if( m == dir ){ //Melhora a complexidade quando todos os pesos das arestas forem iguais 
    m = (esq+dir)/2;
  }

  unionFind d; //Cria uma struct union find, que guarda o número de vertices, o id da componente de cada, o tamanho de cada componente e o número de componentes
  unionFindInit(&d, n); //Inicializa o union find com cada vertice em sua propria componente, tamanhos = 1 e numero de componentes como o numero de vertices


  for( int i=esq; i<=m; i++ ){ //Para cada aresta menor que a mediana
    unionFindUnir(&d, edge[i].oriId, edge[i].destId); //Faz union na estrutura union find pras arestas menores que a mediana
  }
  // No final temos em d.ComponentCount o numero de componentes conexas considerando apenas as arestas com valor menor que a mediana
  
  if( d.componentCount == 1 ){ 
    unionFindFree(&d); //Desaloca o union find (dele, queriamos apenas o número de componentes)
    return MBST(edge, esq, m, n); //Entramos na condição em que as arestas na partição esquerda formam um unico componente conexo, onde MBST subvetor = MBST partição esquerda
  }else{ // A arestas menores que a mediana não foram suficiente para uma unico componente conexo
    superVertice(edge, &d, m+1, dir, n); 
    unionFindFree(&d);
    return MBST(edge, m+1, dir, d.componentCount); //O novo número de arestas é o número de componentes conexas encontradas
  }

}

