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
	while(	l != NULL){
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

void displayPrimeiroMenorTempo(Lista* l, int valor){
	if(lista_Vazia(l)){
		printf("\nNemhum Paciente com Tempo Inferior!\n");		
		return;
	}
	if(menorTempo(l->p,valor)){
		l = l->prox;
		return displayPrimeiroMenorTempo(l,valor); 
	}
		printf("\nProximo Paciente:\n\n");
		pacDisplay(l->p);
		
}
	
	
	


void GerarArquivo( Lista* l){
	FILE* arq = fopen("relatorio.txt","w");
	while(l!=NULL){
		imprimeArquivo(arq,l->p);
		l = l->prox;
	}
	fclose(arq);
}
















