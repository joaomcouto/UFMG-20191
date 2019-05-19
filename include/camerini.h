#ifndef CAMERINI_H
#define CAMERINI_H

#include "constants.h"
#include "union_find.h"

int Camerini(edge_t *e, int n);
int make_super_node( edge_t *e, DSU *d, int l, int r, int n );
int Bottle_neck(edge_t *e, int l, int r, int n);



#endif
