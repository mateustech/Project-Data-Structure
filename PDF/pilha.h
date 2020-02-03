#ifndef PILHA_H
#define PILHA_H

#include "paciente.h"
#include "lista.h"

typedef struct pilha Pilha;

Pilha* novaPilha();
int pilhaVazia(Pilha* pilha);
void exibirPilha(Pilha* pilha);
Pilha* pushPilha(Pilha* pilha, Paciente* p);
Lista* movePilhaPraLista(Pilha* pilha, Lista* lista);
Pilha* liberarPilha(Pilha* pilha);

#endif
