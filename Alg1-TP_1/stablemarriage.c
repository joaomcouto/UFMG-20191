#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stablemarriage.h"
#include "university.h"
#include "student.h"


int printMarriage(Student * student, int numStudents){
    int i,j;
    printf("Grupos com alocacao\n") ;
    for( i = 0; i < numStudents; i++){
        if(student[i].uni != -1) printf("%i %i\n", i+1 , student[i].uni +1) ;
    }
    printf("Candidatos nao alocados\n") ;
    for( i = 0; i < numStudents; i++){
        if(student[i].uni == -1) printf("%i\n", i+1) ;
    }

}

int uniPrefers(University university, Student * student, int proposingStudent){ //dada uma uni e um estudante diz qual do seus currentMatch ela prefere menos que o estudante. Caso nao, retorna 0
    int i ;
    int min = student[university.currentMatch[0]].score;
    int minIndex = 0 ;

    for(i=0; i < university.slots; i++){ //Escolhe o current student da universidade com menor nota
        if (student[university.currentMatch[i]].score < min) { 
            minIndex = i ; 
        } else if(student[university.currentMatch[i]].score == min){ //Se dois currents tem nota igual, seleciona o que tiver menor preferencia pela uni
            if (student[university.currentMatch[i]].proposalCount >= student[university.currentMatch[minIndex]].proposalCount){
                minIndex = i ;
            }
        }
    }

    if(student[proposingStudent].score > student[university.currentMatch[minIndex]].score){ //Se o score do proposing for maior que o score do menor current, troca
        return minIndex + 1;
    } else if(student[proposingStudent].score == student[university.currentMatch[minIndex]].score){ //Se o score deles for igual, vai pegar o que tiver menor preferencia pela uni
        if(student[proposingStudent].proposalCount < student[university.currentMatch[minIndex]].proposalCount){ 
            return minIndex + 1;
        }
     }
    
    return 0 ; //Nao prefere o aluno propondo a nenhum dos seus atuais
}

 int stableMarriage(Student * student, University * university, int numStudents, int numUniversities){
    int proposingStudent ;
    int proposedUniversity ;
    int freeUniSlot ;
    int i,j,k ;
    int droppingStudent ;
    int droppingMatch;
    while(i = existsProposal(student, numStudents)){ //Retorna o ID do proximo estudante a propor
    proposingStudent = i -1 ; //Indice REAL do studante que vai propor
    proposedUniversity = student[proposingStudent].preference[student[proposingStudent].proposalCount] - 1 ; //Index REAL da uni que vai receber a proposta[]
    student[proposingStudent].proposalCount += 1 ;
    if(student[proposingStudent].score >= university[proposedUniversity].score){
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
    }
}