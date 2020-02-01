#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct paciente Paciente;

#include <stdio.h>

Paciente * criarPaciente(char *nome, int tempoExame);

void pacDisplay (Paciente * p);

int pacBusca(Paciente* p,char* nome);

int compara(Paciente* x, Paciente * y);

int menorTempo(Paciente* p,int valor);

void imprimeArquivo(FILE* arq,Paciente* p);
#endif
