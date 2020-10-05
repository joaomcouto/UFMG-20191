#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "mediana.h"
#include "quicksort.h"

int Mediana(aresta *edge, int esq, int dir){
  return MOM(edge, esq, dir, (esq+dir)/2);
}

int Mediana5(aresta *edge, int esq, int dir){

  int valorMaior=-1, valorSegundoMaior=-1, valorTerceiroMaior=-1;
  int indiceMaior=-1, indiceSegundoMaior=-1, indiceTerceiroMaior =-1;
  for( int i=esq; i<=dir; i++ ){
    if( edge[i].peso > valorMaior ){
      indiceMaior = i;
      valorMaior = edge[i].peso;
    }
  }
  for( int i=esq; i<=dir; i++ ){
    if( i!=indiceMaior && edge[i].peso > valorSegundoMaior ){
      indiceSegundoMaior = i;
      valorSegundoMaior = edge[i].peso;
    }
  }
  for( int i=esq; i<=dir; i++ ){
    if( i!=indiceMaior && i!=indiceSegundoMaior && edge[i].peso > valorTerceiroMaior ){
      indiceTerceiroMaior  = i;
      valorTerceiroMaior = edge[i].peso;
    }
  }
  return indiceTerceiroMaior ;
}

int MOM(aresta *edge, int esq, int dir, int k){ // k é a posicao do meio entre a esquerda e a direita

  if( dir-esq+1 <= 5 ){ //Se o tamanho do subvetor passado for menor que 5, ordena com quicksort e retorna o elemento do meio (mediana)
    quicksort(edge, esq, dir);
    return k;
  }

  int it_m=0;
  aresta *m = (aresta*)malloc(((dir-esq+1)/5)*sizeof(aresta)); //Aloca um vetor de arestas com espaço para guardar a mediana de cada grupo de 5 elementos
  for( int i=esq; i+4<=dir; i+=5 ){ //Vai pulando em grupos de 5 em 5, i é o indice da primeira posicao de cada grupo
    int mf = Mediana5(edge, i, i+4); //Em cada grupo acha o indice no vetor de aresta da mediana dos 5 elementos
    m[it_m++] = edge[mf]; //Guarda no m a aresta que tem o peso mediano do grupo de 5
  }

  int mom = m[MOM(m, 0, it_m-1, (it_m-1)/2)].peso; // Acha o peso da mediana das medianas dos grupos de 5. Aqui os indices se referem a m, nao edge
  for( int i=esq; i<=dir; i++ ){ //Encontra o indice, no vetor de arestas, da aresta com peso mediana e coloca troca ele com a ultima posição do subvetor atual (esq a dir)
    if( edge[i].peso == mom ){
      aresta aux = edge[i];
      edge[i] = edge[dir];
      edge[dir] = aux;
      break;
    }
  }
  //Agora a mediana do subvetor esta no final do subvetor (posicao dir) passado pra funcao Mediana na chamada inicial

  free(m);

  int pivot = threeWayPartition(edge, esq, dir); //Sabendo que a mediana já se encontra na ultima posicao(dir), faz o particionamento do subvetor atual
  //pivot é o indice do pivot neste subvetor que agora já foi particionado
//Como queremos o k-esimo menor, chamamos o mom na partição (1 das 3) em que o k-esimo se encontra
  if( pivot == k ){ //
    return pivot;
  }else if( pivot > k ){
    return MOM(edge, esq, pivot-1, k);
  }else{
    return MOM(edge, pivot+1, dir, k);
  }

}
