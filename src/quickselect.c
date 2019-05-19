#include <stdio.h>
#include <stdlib.h>

#include "quickselect.h"
#include "quicksort.h"

int quickselect(edge_t *e, int l, int r, int k){

  if( l==r ){
    return l;
  }

  get_pivot(e, l, r);
  int p = partition(e, l, r);
  if( p == k ){
    return k;
  }else if( p < k ){
    return quickselect(e, p+1, r, k);
  }else{
    return quickselect(e, l, p-1, k);
  }

}
