#ifndef UNION_FIND
#define UNION_FIND

#include "constants.h"

typedef struct{
  int n;
  int *id;
  int *size;
  int comp;
}DSU;

void DSU_build(DSU *d, int n);
int DSU_find(DSU *d, int k);
void DSU_unite(DSU *d, int a, int b);
void DSU_destroy(DSU *d);

#endif
