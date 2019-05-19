#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "constants.h"

void sort(aresta *e, int n );
void get_pivot(aresta *e, int l, int r );
void quicksort(aresta *e, int l, int r );
int partition(aresta *e, int l, int r );

#endif
