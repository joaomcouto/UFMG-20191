#ifndef UF_H
#define UF_H

#include "auxiliar.h"

typedef struct{
  int n;
  int *id;
  int *size;
  int componentCount;
}unionFind;

void unionFindInit(unionFind *d, int n);
int unionFindFind(unionFind *d, int k);
void unionFindUnir(unionFind *d, int a, int b);
void unionFindFree(unionFind *d);

#endif
