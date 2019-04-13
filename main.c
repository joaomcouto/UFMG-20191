#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct 
{
    //int id;
    int score;
    int appNum ;
    int uni ;
    int * preference ;
    int proposalCount ;

} Student ;

typedef struct
{
    //int id ;
    //int * preference ;
    int slots ;
    int score ;
    int * currentMatch ; //vetor com estudantes alocados pra universidade
} University;

/*
int existsProposal(Student * student, int numStudents){  //Dado o conjunto de estudantes, retorna o id do primeiro estudante sem uni e que nao propos pra todas, 0 se nao existir
    int i ;
    for (i = 0; i < numStudents; i++ ){
        if ((student[i].uni == -1) && (student[i].proposalCount < student[i].appNum)){ //studante nao tem uni e ainda nao propos pra todas que quer
            return i + 1;
        }
    }
    return 0 ; 
}

int existsSlot(University university){ //dada uma uni, retorna o id do seu vetor de currentMatch que tem vaga e 0 caso nao tenha
    int i ;
    for(i = 0; i < university.slots; i++){
        if(university.currentMatch[i] == -1) return i+1;
    }
    return 0 ;
}

int uniPrefers(University university, Student * student, int proposingStudent){ //dada uma uni e um estudante diz qual do seus currentMatch ela prefere menos que o estudante. Caso nao, retorna 0
    int i ;
    for(i = 0; i < university.slots; i++){
        if(student[proposingStudent].score > student[university.currentMatch[i]].score){
            return i + 1;
        }
    }
    return 0 ;
}
*/
int main( int argc, char *argv[] )
{
    // ------------------------------------------------- LEITURA 
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
       // university[i].id = i + 1 ;
        fscanf(universities,"%i %i",&university[i].slots, &university[i].score) ;
        university[i].currentMatch = malloc(university[i].slots*sizeof(int)) ;
        for(j = 0; j < university[i].slots ; j++){
            university[i].currentMatch[j] = -1 ;
        }
    }
//---TESTE LEITURA UNIs
    for(i = 0; i < numUniversities; i++){
        printf("%i %i ",university[i].slots, university[i].score) ;
    }
//---ENDTEST


    for(i = 0; i < numStudents; i++){ 
        fscanf(students, "%i %i", &student[i].appNum, &student[i].score) ; 
        student[i].preference = malloc(student[i].appNum*sizeof(int)) ;
        for (j = 0 ; j < student[i].appNum ; j++){
            fscanf(students, "%i", &student[i].preference[j]) ; 
        }
        student[i].uni = -1 ;
        student[i].proposalCount = 0 ; 
    }
    //---------------------------------------------- END LEITURA

//--------TESTE LEITURA STUDENTS
    for(i = 0; i < numStudents; i++){ 
        printf("%i %i ", student[i].appNum, student[i].score) ; 
        for (j = 0 ; j < student[i].appNum ; j++){
            printf("%i ", student[i].preference[j]) ; 
        }
    }
//---------END TEST


int proposingStudent ;
int proposedUniversity ;
int freeUniSlot ;
int k ;
int droppingStudent ;
int droppingMatch;
/*
while(i = existsProposal(student, numStudents)){ //Retorna o ID do proximo estudante a propor
    proposingStudent = i -1 ; //Indice REAL do studante que vai propor
    proposedUniversity = student[proposingStudent].preference[student[proposingStudent].proposalCount] - 1 ; //Index REAL da uni que vai receber a proposta[]
    student[proposingStudent].proposalCount += 1 ;
    if (j = existsSlot(university[proposedUniversity])){ //Dada a uni que vai receber a proposta, se ela tiver vaga, retorna o ID da vaga
        freeUniSlot = j - 1 ; //Indice REAL da vaga vazia dentro do currentMatch
        university[proposedUniversity].currentMatch[freeUniSlot] = proposingStudent ;
        student[proposingStudent].uni = proposedUniversity ;
    } else if(k = uniPrefers(university[proposedUniversity], student, proposingStudent)) { //Dada a uni que recebera a proposta, ja lotada, retorna o ID da vaga ocupada por um aluno que prefere menos
        droppingMatch = k - 1 ; //index real da vaga que sera substituida
        droppingStudent = university[proposedUniversity].currentMatch[droppingMatch] ; 
        student[droppingStudent].uni = - 1;
        student[proposingStudent].uni = proposedUniversity ;
        university[proposedUniversity].currentMatch[droppingMatch] = proposingStudent ;
    }

}
*/

/*
for( i = 0; i < numStudents; i++){
    printf("%i %i ", i , student[i].uni) ;
}
*/


    
    




   return 0 ;
}