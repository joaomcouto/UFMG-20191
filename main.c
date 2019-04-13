#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id ;
    //int * preference ;
    int slots ;
    int score ;
    int * preference ;
} University;

typedef struct 
{
    int id;
    int score;
    int appNum ;
    University * uni ;
    int * preference ;

} Student ;



int main( int argc, char *argv[] )
{
    int numUniversities ;
    int numStudents ;
    FILE *universities ;
    FILE *students ;
    universities = fopen(argv[1], "r") ;
    students = fopen(argv[2], "r") ; 
    fscanf (universities, "%i", &numUniversities) ;
    fscanf (students, "%i", &numStudents) ;
    Student student[numStudents];
    University university[numUniversities] ;
    int i,j ;

    for(i = 0; i < numUniversities; i++){
        university[i].id = i + 1 ;
        fscanf(universities,"%i %i",&university[i].slots, &university[i].score) ;

    }
/*
    for(i = 0; i < numUniversities; i++){
        printf("%i %i",university[i].slots, university[i].score) ;
    }
*/
    

    
    for(i = 0; i < numStudents; i++){ 
        student[i].id = i + 1 ;
        fscanf(students, "%i %i", &student[i].appNum, &student[i].score) ; 
        student[i].preference = malloc(student[i].appNum*sizeof(int)) ;
        for (j = 0 ; j < student[i].appNum ; j++){
            fscanf(students, "%i", &student[i].preference[j]) ; 
        }
        student[i].uni = NULL;
    }

/*
    for(i = 0; i < numStudents; i++){ 
        printf("%i %i ", student[i].appNum, student[i].score) ; 
        for (j = 0 ; j < student[i].appNum ; j++){
            printf("%i ", student[i].preference[j]) ; 
        }
    }
*/




    
    




   return 0 ;
}