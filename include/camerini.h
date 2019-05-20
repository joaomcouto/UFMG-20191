#ifndef CAMERINI_H
#define CAMERINI_H

#include "auxiliar.h"
#include "unionFind.h"

int Camerini(aresta *edge, int n);
int superVertice( aresta *edge, unionFind *d, int esq, int dir, int n );
int MBST(aresta *edge, int esq, int dir, int n);



#endif
