#include <stdio.h>
#include <stdlib.h>

#include "prim.h"

int Prim( int** g, int n ){

   int mx = -1;
   int *min_edge = (int*)malloc(n*sizeof(int));
   int *selected = (int*)malloc(n*sizeof(int));;

   if( min_edge == NULL || selected == NULL ){
     printf("Malloc error\n");
     exit(0);
   }

   for( int i=0; i<n; i++ ){
     min_edge[i] = INF;
     selected[i] = 0;
   }

   min_edge[0] = 0;

   for( int i=0; i<n; i++ ){

     int v = -1;
     for( int j=0; j<n; j++ ){
       if( selected[j] == 0 && (v == -1 || min_edge[v] > min_edge[j]) ){
         v = j;
       }
     }

     selected[v] = 1;
     if( mx < min_edge[v] ){
       mx = min_edge[v];
     }

     for( int j=0; j<n; j++ ) if( j!=v ){
       if( min_edge[j] > g[v][j] ){
         min_edge[j] = g[v][j];
       }
     }

   }

   free(selected);
   free(min_edge);

   return mx;
}
