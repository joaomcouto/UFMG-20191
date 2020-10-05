#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university.h"
#include "student.h"
#include "stablemarriage.h"
#include "experimentalanalysis.h"


int geraAleatorio(int numAlunos, int appNum, int numUniversities){
    int i  , j ; 
    int randnum ;
    for (i = 0 ; i < numAlunos ; i++){
        for (j = 0 ; j < appNum ; j++){
            randnum = rand() % (numUniversities + 1 - 1) + 1 ;
            printf ("%d ", randnum); 
        }
        printf("\n") ; 
    }

}

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
    initializeUniversities(universities,numUniversities ,university ) ;
    initializeStudents(students,numStudents, student);
    stableMarriage(student, university, numStudents, numUniversities) ;
    printMarriage(student, numStudents) ;
    //allocationRateAndAverageFullness(university, numUniversities);
    averageSatisfaction(student, numStudents);

    printf ("\n -------Separator for experimental analysis ------- \n") ;

    srand(time(NULL));
    numStudents = 10 ;
    numUniversities = 5;
    int appNum , i, j;
    //appNum = 7;
    Student studenttest[numStudents] ;
    University universitytest[numUniversities] ;
    //float avgAllocationRate ; 
    double currentAllocationSum ;
    double currentFullnessSum ;
    double currentSatisfactionSum ; 
    int iterations = 10000;

    for (i =1 ; i < 5; i++){
        appNum = i ;
        currentAllocationSum = 0 ;
        currentFullnessSum = 0 ; 
        currentSatisfactionSum = 0 ;
        for (j = 0 ; j < iterations ; j++){
            questao1(numStudents,studenttest,appNum,numUniversities,universitytest) ;   
            stableMarriage(studenttest, universitytest, numStudents, numUniversities) ;
            currentAllocationSum = currentAllocationSum + allocationRate(universitytest, numUniversities);
            currentFullnessSum = currentFullnessSum + averageFullness(universitytest, numUniversities);
            currentSatisfactionSum = currentSatisfactionSum +  averageSatisfaction(studenttest, numStudents);
        }
        printf("Para appnum = %d a allocation eh %f\n", appNum, currentAllocationSum/iterations) ;
        printf("Para appnum = %d a fullness eh %f\n", appNum, currentFullnessSum/iterations) ;
        printf("Para appnum = %d a satisfaction eh %f\n", appNum, currentSatisfactionSum/iterations) ;
        printf ("\n") ;
        

    }

   
/*
    questao1(numStudents,studenttest,appNum,numUniversities,universitytest) ;
    printPreference(studenttest, numStudents); 

    stableMarriage(studenttest, universitytest, numStudents, numUniversities) ;
    allocationRate(universitytest, numUniversities);
    averageFullness(universitytest, numUniversities);
    averageSatisfaction(studenttest, numStudents);


*/
    
    return 0 ;
}