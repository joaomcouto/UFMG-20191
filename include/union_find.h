#ifndef UNION_FIND
#define UNION_FIND

#include "constants.h"

typedef struct{
  int n;
  int *id;
  int *size;
  int comp;
}unionFind;

void DSU_build(unionFind *d, int n);
int DSU_find(unionFind *d, int k);
void DSU_unite(unionFind *d, int a, int b);
void DSU_destroy(unionFind *d);

#endif
