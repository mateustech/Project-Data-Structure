#ifndef FILA_H
#define FILA_H

#include "paciente.h"
#include "pilha.h"

typedef struct fila Fila;

Fila* novaFila();
int filaVazia(Fila* fila);
void exibirFila(Fila* fila);
Paciente* ultimoPacienteDaFila(Fila* fila);
Fila* pushFila(Fila* fila, Paciente* p);
Fila* liberarFila(Fila* fila);
Fila* popFila(Fila* fila);
Paciente* buscarPaciente(Fila* fila, char* nome);
Pilha* moveFilaPraPilha(Fila* fila, Pilha* pilha);

#endif
