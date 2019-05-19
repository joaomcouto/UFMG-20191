#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "constants.h"

void sort(edge_t *e, int n );
void get_pivot(edge_t *e, int l, int r );
void quicksort(edge_t *e, int l, int r );
int partition(edge_t *e, int l, int r );

#endif
