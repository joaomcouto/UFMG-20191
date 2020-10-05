#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university.h"
#include "student.h"
#include "experimentalanalysis.h"
#include <math.h> 

double allocationRate (University * university, int numUniversities){
    int i , j;
    float totalSlots = 0  ;
    float filledSlots = 0;
    float ratioSum = 0 ;
    float avgFullnessRate = 0 ; 
    float currentFilled = 0 ;

    for (i=0 ; i < numUniversities; i++){
        currentFilled = 0 ;
        totalSlots = totalSlots + university[i].slots ;
        for (j= 0 ; j < university[i].slots; j++){
            if (university[i].currentMatch[j] != -1){
                currentFilled += 1 ;
                filledSlots = filledSlots + 1;
            }
        }
        ratioSum += currentFilled/university[i].slots ; 
    }
    float totalAllocationRate = 0 ;  ;
    totalAllocationRate = filledSlots/totalSlots;
    avgFullnessRate = ratioSum/numUniversities ; 
    //printf ("A taxa de alocação TOTAL é de %f\n", totalAllocationRate);
    return totalAllocationRate;
}

double averageFullness (University * university, int numUniversities){
    int i , j;
    float totalSlots = 0  ;
    float filledSlots = 0;
    float ratioSum = 0 ;
    float avgFullnessRate = 0 ; 
    float currentFilled = 0 ;

    for (i=0 ; i < numUniversities; i++){
        currentFilled = 0 ;
        totalSlots = totalSlots + university[i].slots ;
        for (j= 0 ; j < university[i].slots; j++){
            if (university[i].currentMatch[j] != -1){
                currentFilled += 1 ;
                filledSlots = filledSlots + 1;
            }
        }
        ratioSum += currentFilled/university[i].slots ; 
    }
    float totalAllocationRate = 0 ;  ;
    totalAllocationRate = filledSlots/totalSlots;
    avgFullnessRate = ratioSum/numUniversities ; 
    //printf ("Media da taxa de preenchimento: %f\n", avgFullnessRate ) ;
    return avgFullnessRate ; 
}

double averageSatisfaction(Student * student, int numStudents){
    int i , j ;
    float satisfactionSum = 0 ;
    float currentSatisfaction = 0 ;
    float avgSatisfaction = 0 ;
    for (i = 0 ; i < numStudents ; i++){
        if (student[i].uni != -1){
            for(j= 0; j < student[i].appNum; j++){
                if (student[i].preference[j]-1 == student[i].uni){
                    currentSatisfaction = 1/log2(j+1+1) ;
                }
            }
        } else {currentSatisfaction = 0 ; }
        satisfactionSum += currentSatisfaction ;
    }
    avgSatisfaction = satisfactionSum/numStudents ;
    //printf("A satisfacao media foi de: %f\n", avgSatisfaction ); 
    return avgSatisfaction ;
}



int analiseAppNum(){
    
}

int questao1(int numStudents, Student * student, int appNum, int numUniversities, University * university){
    int i,j ;
    int vetor[numUniversities] ;
    int max = numUniversities - 1;
    int randNum, temp ;
    for(i = 0; i < numStudents; i++){ 
        student[i].appNum = appNum ;
        student[i].score = rand() % (100 + 1 - 60) + 60 ;
        //student[i].score = 200 + i;
        student[i].preference = malloc(student[i].appNum*sizeof(int)) ;
        max = numUniversities - 1;
        for (j=0 ; j < numUniversities ; j++){
            vetor[j] = j + 1 ;
        }
        for (j = 0 ; j < student[i].appNum ; j++){ //Dado o numero de universidades que um aluno pode escolher, gera um vetor com preferencias aleatorias
            randNum = rand() % (max + 1 - 0) + 0 ;
            student[i].preference[j] = vetor[randNum] ;
            temp = vetor[randNum] ;
            vetor[randNum] = vetor[max] ;
            vetor[max] = temp ;
            max = max - 1;
        }
    student[i].uni = -1 ;
    student[i].proposalCount = 0 ; 
    }


   
    for(i = 0; i < numUniversities; i++){
       // university[i].slots = rand() % (numStudents + 1 - 1) + 1 ;
        university[i].slots = 3 ;
        university[i].score = rand() % (100 + 1 - 60) + 60 ;
        university[i].currentMatch = malloc(university[i].slots*sizeof(int)) ;
        for(j = 0; j < university[i].slots ; j++){
             university[i].currentMatch[j] = -1 ;
        }
    }
 }
        


int printPreference(Student * student, int numStudents){
    int i, j;
    for(i = 0; i < numStudents; i++){ 
        printf("Vetor preferencia:\n");
        for (j = 0 ; j < student[i].appNum ; j++){
            printf ("%d ", student[i].preference[j]) ;
        }
        printf ("\n") ;
    }

}
