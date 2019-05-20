#ifndef CAMERINI_H
#define CAMERINI_H

#include "auxiliar.h"
#include "union_find.h"

int Camerini(aresta *e, int n);
int superVertice( aresta *e, unionFind *d, int l, int r, int n );
int MBST(aresta *e, int l, int r, int n);



#endif
