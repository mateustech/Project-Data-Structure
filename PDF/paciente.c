#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct paciente{
    char nome[50];
    int tempoExame;

};
typedef struct paciente Paciente;

Paciente * criarPaciente(char *nome, int tempoExame){
    Paciente *p;
    p = (Paciente*) malloc(sizeof(Paciente));
	
    if(!p) {
        printf("Problema de alocao");
        exit(0);
    }
    strcpy(p->nome,nome);
    p->tempoExame = tempoExame;

    return p;
}

void pacDisplay(Paciente * p){
	printf("Nome: %s\n",p->nome);
	printf("Tempo de Exame: %d\n\n",p->tempoExame);
}

int pacBusca(Paciente* p,char* nome){
	if(strcmp(p->nome,nome)==0){
			printf("\nNome: %s", p->nome);
            printf("\nTempo de Exame: %d", p->tempoExame);
            return 1;
	}
	else{
		return 0;
	}
}












