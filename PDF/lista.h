#ifndef LISTA_H
#define LISTA_H

#include "paciente.h"

typedef struct lista Lista;

Lista* novaLista();
int listaVazia(Lista* lista);
void exibirLista(Lista* lista);
Lista* pushLista(Lista* lista, Paciente* p);
void displayPrimeiroMenorTempo(Lista* lista, int valor);
void gerarArquivo(Lista* lista);
Lista* liberarLista(Lista* lista);

#endif
