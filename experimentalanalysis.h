#ifndef EXPERIMENTALANALYSIS_H_INCLUDED
#define EXPERIMENTALANALYSIS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university.h"
#include "student.h"
#include "stablemarriage.h"

int allocationRateAndAverageFullness (University * university, int numUniversities) ; 
int averageSatisfaction(Student * student, int numStudents); 

#endif