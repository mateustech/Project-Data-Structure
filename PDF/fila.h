#ifndef FILA_H
#define FILA_H

#include "paciente.h"
#include "pilha.h"

typedef struct fila Fila;

Fila* nova_fila();

int fila_vazia(Fila *f);

void exibirFila(Fila *fila);

Fila* pushF(Fila* u, Paciente * p);

Fila* mapearNo(Fila*  f);

Fila* pop(Fila* f);

Paciente* buscaPaciente(Fila* fila,char * nome);

Pilha* move_Fila_Pilha(Fila* fila, Pilha* pi);

#endif


