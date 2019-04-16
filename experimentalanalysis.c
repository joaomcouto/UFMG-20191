#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university.h"
#include "student.h"
#include "experimentalanalysis.h"
#include <math.h> 

int allocationRateAndAverageFullness (University * university, int numUniversities){
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
    printf ("A taxa de alocação TOTAL é de %f\n", totalAllocationRate);
    printf ("Media da taxa de preenchimento: %f\n", avgFullnessRate ) ;
    return filledSlots/totalSlots;
}

int averageSatisfaction(Student * student, int numStudents){
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
    printf("A satisfacao media foi de: %f\n", avgSatisfaction ); 

}