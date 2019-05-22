#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#include "camerini.h"
#include "mediana.h"
#include "quicksort.h"
#include "unionFind.h"


int Camerini(aresta *edge, int n){
  return MBST(edge, 0, ((n*(n-1))/2)-1, n); //A chama da MBST eh posicional.. porque/como n*n-1)/2 quando temos n2 arestas
}

void superVertice( aresta *edge, unionFind *d, int esq, int dir, int n ){ //Recebe o vetor de arestas todo, n = numero de vertices do subvetor que chamou o super vertice
  int *rep = (int*)malloc(n*sizeof(int)); //Um vetor com
  //Pra cada representando de cada componente conexo atribuir um inteior de 0 a n -1
  //
  int i ; 
  for(i = 0 ; i < n ; i ++ ) rep[i] = - 1 ;


  int comp = 0;

  for( int i=0; i<n; i++ ){ //Itera entre todos os vertices 
    if( rep[unionFindFind(d, i)] == -1 ){ // E pra cada um acha
      rep[unionFindFind(d, i)] = comp++; // Pra cada componente conexo formado com as arestas menores que
    }
  }
  //No rep os representantes de componentes vao ter o valor do contador, e o resto, -1
  //A ideia é que agora o que importa são as arestas maiores que a mediana

  for( int i=esq; i<=dir; i++ ){ //Transforma as arestas pra que conectem as componentes (que sao os novos vertices)
  //Tem passado a mediana como limite esquerdo, agora as arestas membros da particao menor nao sao alteradas, mas na real tanto faz
    edge[i].oriId = rep[unionFindFind(d, edge[i].oriId)];
    edge[i].destId = rep[unionFindFind(d, edge[i].destId)];
  }
//Agora as arestas tem como vertices numeros entre 0 e n-1 que sao os indices das componentes componexas
  free(rep);

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

  if( m == dir ){ //Melhora a complexidade quando todos os pesos das arestas foram iguais 
    m = (esq+dir)/2;
  }

  unionFind d; //Cria uma struct union find, que guarda o número de vertices, o id da componente de cada, o tamanho de cada componente e o número de componentes
  unionFindInit(&d, n); //Inicializa o union find com cada vertice em sua propria componente, tamanhos = 1 e numero de componentes como o numero de vertices
 // AO inves de matriz de adjancencia rodar DFS edge achar os componentes, faz union find

  for( int i=esq; i<=m; i++ ){ //Para cada aresta menor que a mediana
    unionFindUnir(&d, edge[i].oriId, edge[i].destId); //Faz union na estrutura union find pras arestas menores que a mediana
  }
  // No final temos em d.ComponentCount o numero de componentes conexas considerando apenas as arestas com valor menor que a mediana
  
  if( d.componentCount == 1 ){ 
    unionFindFree(&d); //Desaloca o union find (nele, queriamos apenas o número de componentes)
    return MBST(edge, esq, m, n); //Entramos na condição em que as arestas na partição esquerdao forma um unico componente conexo, onde MBST subvetor = MBST partição esquerda
  }else{ // A arestas menores que a mediana não foram suficient para uma unico componente conexo
    superVertice(edge, &d, m+1, dir, n); //n é o numero do total de vertices depois da criar os super vertices e mudar as arestas
    //N eh o novo numero de nós
    unionFindFree(&d);
    return MBST(edge, m+1, dir, d.componentCount); //Anda pra direita, pega todas maiores que a mediana recursivamente
  }

}

