#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "auxiliar.h"

void sort(aresta *e, int n );
void get_pivot(aresta *e, int l, int r );
void quicksort(aresta *e, int l, int r );
int threeWayPartition(aresta *e, int l, int r );

#endif
