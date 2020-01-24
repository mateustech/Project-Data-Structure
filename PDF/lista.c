#include "lista.h"
#include "paciente.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	Paciente* p;
	struct lista* prox;
} Lista;


Lista* nova_Lista(){
	return NULL;
}

int lista_Vazia(Lista* l){
	if(l == NULL){
		return 1;
	}else{
		return 0;
	}
}

void exibirLista(Lista* l){
	while(l != NULL){
		pacDisplay(l->p);
		l = l->prox;
	}
}

Lista* pushL(Lista* u, Paciente * p){
	Lista* temp = u;
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->p = p;
	novo->prox = NULL;
	
	if(lista_Vazia(u)){
		return novo;
	}
	
	while(temp->prox != NULL){
		
		temp = temp->prox;
	}
	
		temp->prox = novo;
		return u;	
	
	
}

Lista* displayPrimeiroMenorTempo(Lista* l, int valor){
	while(!menorTempo(l->p,valor)){ // > 
		l = l->prox;
	}
	return l;
}

void GerarArquivo( Lista* l){
	while(l!=NULL){
		imprimeArquivo(l->p);
		l = l->prox;
	}
}
















