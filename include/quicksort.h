#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "auxiliar.h"

void sort(aresta *edge, int n );
void get_pivot(aresta *edge, int esq, int dir );
void quicksort(aresta *edge, int esq, int dir );
int threeWayPartition(aresta *edge, int esq, int dir );

#endif
