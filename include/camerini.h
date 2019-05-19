#ifndef CAMERINI_H
#define CAMERINI_H

#include "constants.h"
#include "union_find.h"

int Camerini(aresta *e, int n);
int make_super_node( aresta *e, unionFind *d, int l, int r, int n );
int Bottle_neck(aresta *e, int l, int r, int n);



#endif
