#include "paciente.h"
#include "fila.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila {
	Paciente * p;
	struct fila * prox;
}Fila;

Fila* nova_fila(){
	return NULL;
}

int fila_vazia(Fila *f){ /* verifica se a fila esta vazia */
	if(f==NULL)
		return 1;
	else
		return 0;
}

void exibirFila(Fila *fila){
	printf("--------------------------------------\n");
	printf("              Pacientes\n");
    while(fila_vazia(fila)==0){
		pacDisplay(fila->p);
        fila = fila->prox;
    }
}

Fila* push(Fila* u, Paciente * p){
	Fila* temp = u;
	Fila* novo = (Fila*)malloc(sizeof(Fila));
	novo->p = p;
	novo->prox = NULL;
	
	if(fila_vazia(u)){
		return novo;
	}

	while(temp->prox != NULL){
		temp = temp->prox;
	}
	temp->prox = novo;
	return u;
}
//tem que passar para o tad paciente.h
void buscarPaciente(Fila *fila, char *nome){
	Paciente * p = fila->p;
	int achou = 0;
	while(p != NULL){
		int yes = pacBusca(p,nome);
		if(yes == 1){
			achou ++;
			break;
		}
		if(!fila_vazia(fila->prox)){
			fila = fila->prox;
		}else{
			break;
		}
	
		p = fila->p;
	}
	if(achou == 0){
		printf("Paciente Não Encontrado!\n");
	}
}








