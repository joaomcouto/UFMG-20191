#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


int initializeStudents(FILE * students, int numStudents, Student * student){
    int i,j ;
    for(i = 0; i < numStudents; i++){ 
        fscanf(students, "%i %i", &student[i].appNum, &student[i].score) ; 
        student[i].preference = malloc(student[i].appNum*sizeof(int)) ;
        for (j = 0 ; j < student[i].appNum ; j++){
            fscanf(students, "%i", &student[i].preference[j]) ; 
        }
    student[i].uni = -1 ;
    student[i].proposalCount = 0 ; 
    }
 }

 int existsProposal(Student * student, int numStudents){  //Dado o conjunto de estudantes, retorna o id do primeiro estudante sem uni e que nao propos pra todas, 0 se nao existir
    int i ;
    for (i = 0; i < numStudents; i++ ){
        if ((student[i].uni == -1) && (student[i].proposalCount < student[i].appNum)){ //studante nao tem uni e ainda nao propos pra todas que quer
            return i + 1;
        }
    }
    return 0 ; 
}