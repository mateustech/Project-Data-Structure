#ifndef PACIENTE_H
#define PACIENTE_H

#include <stdio.h>

typedef struct paciente Paciente;

Paciente * criarPaciente(char* nome, int tempoExame);
void pacDisplay(Paciente* p);
int pacBusca(Paciente* p, char* nome);
int compara(Paciente* x, Paciente* y);
int menorTempo(Paciente* p, int valor);
void imprimeArquivo(FILE* arq, Paciente* p);
void liberaPaciente(Paciente* paciente);

#endif
