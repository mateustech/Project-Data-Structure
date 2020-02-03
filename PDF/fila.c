#include "paciente.h"
#include "fila.h"
#include "pilha.h"

#include <stdio.h>	/*printf*/
#include <stdlib.h>	/*malloc, free*/

typedef struct fila {
	Paciente* p;
	struct fila* prox;
}Fila;

/**
* Função: novaFila
* Descrição: cria uma fila vazia
* Parâmetros: nada
* Retorno: NULL
**/
Fila* novaFila(){
	return NULL;
}

/**
* Função: filaVazia
* Descrição: verifica se uma fila passada por parametro
*            estar vazia.
*			 Se sim, retorna 1, senão, retorna 0.
* Parâmetros: fila
* Retorno: 0 ou 1
**/
int filaVazia(Fila* fila){
	if(fila==NULL)
		return 1;
	else
		return 0;
}

/**
* Função: exibirFila
* Descrição: imprime os dados dos pacientes de uma fila
*            passada por parametro
* Parâmetros: fila
* Retorno: nada
**/
void exibirFila(Fila* fila){
	printf("---------------- Pacientes ----------------\n");
    while(filaVazia(fila)==0){
		pacDisplay(fila->p);
        fila = fila->prox;
    }
    printf("-------------------------------------------\n\n\n");
}

/**
* Função: ultimoPacienteDaFila
* Descrição: busca o ultimo paciente de uma fila
*            passada por parametro.
* Parâmetros: fila
* Retorno: ultimo paciente ou NULL (caso a fila seja vazia)
**/
Paciente* ultimoPacienteDaFila(Fila* fila){
	if(filaVazia(fila)){
		return NULL;
	}
	else{
		Fila* temp = fila;
		while(temp->prox != NULL){
			temp = temp->prox;
		}
		return temp->p;	
	}
}

/**
* Função: pushFila
* Descrição: adiciona no final de uma fila 
*            um novo no contendo um pacente
*			 passado por parametro.
* Parâmetros: fila, p
* Retorno: fila atualizada
**/
Fila* pushFila(Fila* fila, Paciente* p){
	Fila* temp = fila;
	Fila* novo = (Fila*)malloc(sizeof(Fila));
	novo->p = p;
	novo->prox = NULL;
	
	if(filaVazia(fila)){
		return novo;
	}
	
	while(temp->prox != NULL){
		temp = temp->prox;
	}
	
	temp->prox = novo;
	return fila;
}

/**
* Função: popFila
* Descrição: elimina a cabeca de uma fila recebida 
*            por parametro
* Parâmetros: fila
* Retorno: calda da fila
**/
Fila* popFila(Fila* fila){
 	if(filaVazia(fila))
	   return NULL;
	Fila *temp = fila -> prox;
	free(fila);		// tava depois
	
	return temp;
}

/**
* Função: liberarFila
* Descrição: libera o espaco alocado de uma fila
*            passada por parametro
* Parâmetros: fila
* Retorno: fila vazia
**/
Fila* liberarFila(Fila* fila){
	while(!filaVazia(fila)){
		fila = popFila(fila);
		if(filaVazia(fila)){
			return NULL;
		}
		fila = fila->prox;
	}
	
	return NULL;
}

/**
* Função: buscarPaciente
* Descrição: busca pelo nome um paciente em uma fila, 
*            sendo ambos passados por parametros
* Parâmetros: fila, nome
* Retorno: paciente ou NULL (caso a fila seja vazia)
**/
Paciente* buscarPaciente(Fila* fila, char* nome){
	if(filaVazia(fila)){
		return NULL;
	}
	else{
		Paciente * p = fila->p;
		while(p != NULL){
			int yes = pacBusca(p,nome);
			if(yes == 1){
				return p;
			}
			if(!filaVazia(fila->prox)){
				fila = fila->prox;
			}else{
				break;
			}
	
			p = fila->p;
		}
	}
	return NULL;
}

/**
* Função: moveFilaPraPilha
* Descrição: copia na ordem inversa os pacientes armazenados
*            em uma fila passada por parametro para uma pilha
*			 tambem passada por parametro. 
*			 A funcao pushPilha eh usada para ir montando
*			 a pilha.
* Parâmetros: fila, pilha
* Retorno: pilha
**/
Pilha* moveFilaPraPilha(Fila* fila, Pilha* pilha){
	while(!filaVazia(fila)){
		pilha = pushPilha(pilha,fila->p);
		fila = fila->prox;
	}
	return pilha;
}
