#ifndef LISTA_H
#define LISTA_H

#include "paciente.h"
#include <stdio.h>

typedef struct lista Lista;

Lista* nova_Lista();

int lista_Vazia(Lista* l);

void exibirLista(Lista* l);

Lista* pushL(Lista* u, Paciente * p);

Lista* displayPrimeiroMenorTempo(Lista * l, int valor);

void GerarArquivo(Lista* l);


#endif
