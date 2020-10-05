#ifndef UNIVERSITY_H_INCLUDED
#define UNIVERSITY_H_INCLUDED

typedef struct
{
    int slots ;
    int score ;
    int * currentMatch ; //vetor com estudantes alocados pra universidade
} University;


int initializeUniversities(FILE * universities, int numUniversities, University * university ) ;

int existsSlot(University university);


#endif