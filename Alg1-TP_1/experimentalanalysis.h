#ifndef EXPERIMENTALANALYSIS_H_INCLUDED
#define EXPERIMENTALANALYSIS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university.h"
#include "student.h"
#include "stablemarriage.h"

double allocationRate (University * university, int numUniversities) ;
double averageFullness (University * university, int numUniversities);
double averageSatisfaction(Student * student, int numStudents); 
int questao1(int numStudents, Student * student, int appNum, int numUniversities, University * university);
int printPreference(Student * student, int numStudents);

#endif