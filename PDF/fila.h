#ifndef FILA_H
#define FILA_H
#include "paciente.h"

typedef struct fila Fila;
Fila* nova_fila();
int fila_vazia(Fila *f);
void exibirFila(Fila *fila);
Fila* push(Fila* u, Paciente * p);
void buscaPaciente(Fila* fila,char * nome);
#endif
