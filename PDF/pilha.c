#include "pilha.h"
#include "paciente.h"

#include <stdio.h>	/*printf*/
#include <stdlib.h>	/*malloc*/

typedef struct pilha{
	Paciente * p;
	struct pilha * prox;
}Pilha;

/**
* Função: novaPilha
* Descrição: cria uma pilha vazia
* Parâmetros: nada
* Retorno: NULL
**/
Pilha* novaPilha(){
	return NULL;
}

/**
* Função: pilhaVazia
* Descrição: verifica se uma pilha passada por parametro
*            estar vazia.
*			 Se sim, retorna 1, senão, retorna 0.
* Parâmetros: pilha
* Retorno: 0 ou 1
**/
int pilhaVazia(Pilha* pilha){
	if(pilha == NULL){
		return 1;
	}else{
		return 0;
	}
}

/**
* Função: exibirPilha
* Descrição: imprime os dados dos pacientes de uma pilha
*            passada por parametro
* Parâmetros: pilha
* Retorno: nada
**/
void exibirPilha(Pilha* pilha){
	printf("---------------- Pacientes ----------------\n");
	while(!pilhaVazia(pilha)){
		pacDisplay(pilha->p);
		pilha = pilha->prox;
	}
	printf("-------------------------------------------\n\n\n");
}

/**
* Função: pushPilha
* Descrição: adiciona no topo de uma pilha
*            um novo no contendo um pacente
*			 passado por parametro.
* Parâmetros: pilha, p
* Retorno: pilha atualizada
**/
Pilha* pushPilha(Pilha* pilha, Paciente* p){
	Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
	novo->p = p;
	novo->prox = pilha;
	pilha = novo;
	return pilha;
}

/**
* Função: movePilhaPraLista
* Descrição: copia na mesma ordem os pacientes armazenados
*            em uma pilha passada por parametro para uma lista
*			 tambem passada por parametro. 
*			 A funcao pushLista eh usada para ir montando
*			 a lista desejada.
* Parâmetros: pilha, lista
* Retorno: lista
**/
Lista* movePilhaPraLista(Pilha* pilha, Lista* lista){
	while(!pilhaVazia(pilha)){
		lista = pushLista(lista, pilha->p);
		pilha = pilha->prox;
	}
	return lista;
}

/**
* Função: liberarPilha
* Descrição: libera o espaco alocado de uma pilha
*            passada por parametro
* Parâmetros: pilha
* Retorno: pilha vazia
**/
Pilha* liberarPilha(Pilha* pilha){
	while(!pilhaVazia(pilha)){
		Pilha* temp = pilha->prox;
		free(pilha);
		pilha = NULL;
		pilha = temp;
	}
	return NULL;
}
