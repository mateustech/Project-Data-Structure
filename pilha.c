#include "pilha.h"
#include "paciente.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
	Paciente * p;
	struct pilha * prox;
}Pilha;

Pilha* nova_Pilha(){
	return NULL;
}

int pilhaVazia(Pilha* p){
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
}

Pilha* topo(Pilha* p){
	return p;
}

void exibirPilha(Pilha* p){
	while(p != NULL){
		pacDisplay(p->p);
		p = p->prox;
	}
}

Pilha* pushP(Pilha* p,Paciente* x){
	Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
	novo->p = x;
	novo->prox = p;
	p = novo;
	return p;
}
