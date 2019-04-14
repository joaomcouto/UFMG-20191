#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university.h"
#include "student.h"
#include "stablemarriage.h"

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

    return 0 ;
}