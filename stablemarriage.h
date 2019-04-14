#ifndef STABLEMARRIAGE_H_INCLUDED
#define STABLEMARRIAGE_H_INCLUDED

#include "student.h"
#include "university.h"

int printMarriage(Student * student, int numStudents) ; 
int uniPrefers(University university, Student * student, int proposingStudent) ;
int stableMarriage(Student * student, University * university, int numStudents, int numUniversities) ;

#endif