#ifndef PILHA_H
#define PILHA_H

#include "paciente.h"
#include "lista.h"

typedef struct pilha Pilha;

Pilha* nova_Pilha();

int pilhaVazia(Pilha* p);

void exibirPilha(Pilha* p);//estudar a necessidade dessa função

Pilha* pushP(Pilha* p,Paciente* x);

Lista* move_Pilha_Lista(Pilha* pi ,Lista* l);
#endif
