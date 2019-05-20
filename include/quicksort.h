#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "auxiliar.h"

void sort(aresta *edge, int n );
void get_pivot(aresta *edge, int l, int r );
void quicksort(aresta *edge, int l, int r );
int threeWayPartition(aresta *edge, int l, int r );

#endif
