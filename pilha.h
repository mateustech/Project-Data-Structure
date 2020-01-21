#ifndef PILHA_H
#define PILHA_H

#include "paciente.h"

typedef struct pilha Pilha;

Pilha* nova_Pilha();

int pilhaVazia(Pilha* p);

Pilha* topo(Pilha* p); 

void exibirPilha(Pilha* p);//estudar a necessidade dessa função

Pilha* pushP(Pilha* p,Paciente* x);
#endif
