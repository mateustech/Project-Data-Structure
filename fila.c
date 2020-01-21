#include "paciente.h"
#include "fila.h"

#define S "Paciente Adicionado Com Sucesso!"
#define N "Nao foi possivel adicionar o paciente!"

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

Fila* pushF(Fila* u, Paciente * p){
	Fila* temp = u;
	Fila* novo = (Fila*)malloc(sizeof(Fila));
	novo->p = p;
	novo->prox = NULL;
	
	if(fila_vazia(u)){
		system("color 02");
		printf("\n%s\n",S);
		return novo;
	}
	
	while(temp->prox != NULL){
		
		temp = temp->prox;
	}
	if(compara(temp->p,novo->p)){
		temp->prox = novo;
		system("color 02");
		printf("\n%s\n",S);
		return u;	
	}
		system("color 04");
		printf("\n%s\n",N);
		return u;
	
	
}

Fila* pop(Fila* f){
 	if(fila_vazia(f))
	   return NULL;
	Fila *temp = f -> prox;
	free(f);
	return temp;
}

Paciente* buscarPaciente(Fila *fila, char *nome){
	Paciente * p = fila->p;
	int achou = 0;
	while(p != NULL){
		int yes = pacBusca(p,nome);
		if(yes == 1){
			return p;
		}
		if(!fila_vazia(fila->prox)){
			fila = fila->prox;
		}else{
			break;
		}
	
		p = fila->p;
	}
	return NULL;
}









