#ifndef CAMERINI_H
#define CAMERINI_H

#include "auxiliar.h"
#include "union_find.h"

int Camerini(aresta *edge, int n);
int superVertice( aresta *edge, unionFind *d, int l, int r, int n );
int MBST(aresta *edge, int l, int r, int n);



#endif
