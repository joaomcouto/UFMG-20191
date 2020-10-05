#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

typedef struct 
{
    int score;
    int appNum ;
    int uni ;
    int * preference ;
    int proposalCount ;

} Student ;

int initializeStudents(FILE * students, int numStudents, Student * student) ;

 int existsProposal(Student * student, int numStudents) ;

#endif