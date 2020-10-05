#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university.h"


int initializeUniversities(FILE * universities, int numUniversities, University * university ){
    int i,j ;
    for(i = 0; i < numUniversities; i++){
        // university[i].id = i + 1 ;
        fscanf(universities,"%i %i",&university[i].slots, &university[i].score) ;
        university[i].currentMatch = malloc(university[i].slots*sizeof(int)) ;
        for(j = 0; j < university[i].slots ; j++){
             university[i].currentMatch[j] = -1 ;
        }
    }
    return 0;
 }

int existsSlot(University university){ //dada uma uni, retorna o id do seu vetor de currentMatch que tem vaga e 0 caso nao tenha
    int i ;
    for(i = 0; i < university.slots; i++){
        if(university.currentMatch[i] == -1) return i+1;
    }
    return 0 ;
}
