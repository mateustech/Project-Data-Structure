#include "paciente.h"

#include <stdio.h>	/*printf, puts, fprintf*/
#include <stdlib.h> /*free, exit*/
#include <string.h> /*strcpy, strcmp*/

typedef struct paciente{
    char nome[50];
    int tempoExame;
} Paciente;

/**
* Função: criarPaciente
* Descrição: aloca dinamicamente uma estrutura do tipo Paciente,
*            configurando as suas informações com valores passados
*            por parâmetro
* Parâmetros: nome, tempoExame
* Retorno: estrutura do paciente alocada
**/
Paciente * criarPaciente(char* nome, int tempoExame){
    Paciente *p;
    p = (Paciente*) malloc(sizeof(Paciente));
	
    if(!p) {
        printf("Problema de alocacao");
        exit(0);
    }
    strcpy(p->nome,nome);
    p->tempoExame = tempoExame;

    return p;
}

/**
* Função: pacDisplay
* Descrição: imprime os dados de um paciente passado
*            por parâmetro
* Parâmetros: paciente
* Retorno: nada
**/
void pacDisplay(Paciente* p){
	printf("Nome: %s\n",p->nome);
	printf("Tempo de Exame: %d\n",p->tempoExame);
}

/**
* Função: pacBusca
* Descrição: verifica se um dado paciente possui nome 
*            igual a um dado nome passado por parâmetro.
*            Se sim, retorna 1, senao, retorna 0.
* Parâmetros: p, nome
* Retorno: 0 ou 1
**/
int pacBusca(Paciente* p, char* nome){
	if(strcmp(p->nome,nome)==0){
        return 1;
	}
	else{
		return 0;
	}
}

/**
* Função: compara
* Descrição: verifica se um paciente x passado por parametro
*            possui tempo de exame menor ou igual ao tempo de
*            exame de um paciente y tambem passado por parâmetro.
* 			 Se sim, retorna 1, senao, retorna 0;
* Parâmetros: x, y
* Retorno: 0 ou 1
**/
int compara(Paciente* x, Paciente* y){
	if(x->tempoExame <= y->tempoExame){
		return 1;
	}else{
		return 0;
	}
}

/**
* Função: menorTempo
* Descrição: verifica se o tempo de exame de um dado paciente
*            passado por parametro eh maior ou igual a um dado 
*            valor de tempo tambem passado por parametro.
*			 Se sim, retorna 1, senão, retorna 0.
* Parâmetros: p, valor
* Retorno: 0 ou 1
**/
int menorTempo(Paciente* p, int valor){
	if(p->tempoExame >= valor){
		return 1;
	}else{
		return 0;
	}
}

/**
* Função: imprimeArquivo
* Descrição: recebe como parametros um arquivo pronto para
*            ser escrito e um paciente cujos dados deseja-se  
*            salvar no arquivo e realiza essa operacao
* Parâmetros: arq, p
* Retorno: nada
**/
void imprimeArquivo(FILE* arq, Paciente* p){
	if(!arq){
		puts("Error na abertura do Arquivo.\n");
	}
	fprintf(arq,"Nome: %s\tTempo de Exame: %d\n",p->nome,p->tempoExame);	
}

/**
* Função: liberaPaciente
* Descrição: recebe um paciente como parametro e libera
*            o espaco de memoria ocupado por esse paciente
* Parâmetros: paciente
* Retorno: nada
**/
void liberaPaciente(Paciente* paciente){
	free(paciente);
}
