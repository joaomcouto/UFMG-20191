#ifndef UNION_FIND
#define UNION_FIND

#include "constants.h"

typedef struct{
  int n;
  int *id;
  int *size;
  int comp;
}unionFind;

void unionFindInit(unionFind *d, int n);
int unionFindFind(unionFind *d, int k);
void unionFindUnir(unionFind *d, int a, int b);
void unionFindFree(unionFind *d);

#endif
