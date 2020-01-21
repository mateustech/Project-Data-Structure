#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "paciente.h"
#include "fila.h"
#include "pilha.h"
#include "lista.h"


int main() {
	setlocale(LC_ALL , "Portuguese");
	
	int opcao,opcaoSub,valor, tempoExame;
	char nome[50];
	
	Fila * f = nova_fila(); //fila.h
	Pilha* pi = nova_Pilha(); //pilha.h
	Lista* l = nova_Lista(); //lista.h
	
	do{
        do{
        	
            printf("\n ------------------------------------");
            printf("\n|                                    |");
            printf("\n|   1. CADASTRAR PACIENTE            |");//usando
            printf("\n|   2. BUSCAR PACIENTE               |");//usando
            printf("\n|   3. PRÓXIMO PACIENTE              |");
            printf("\n|   4. ATENDER FILA HOSPITAL         |");
            printf("\n|   5. IMPRIMIR DADOS                |");//usando com submenu
            printf("\n|   0. SAIR                          |");//default
            printf("\n|                                    |");
            printf("\n ------------------------------------\n >>> ");
            scanf("%d", &opcao);
        } while(opcao < 0 || opcao > 5);
		
        switch(opcao){
            case 1:
            	
                printf("Informe o nome do Paciente:");
                scanf("%s",nome);
                printf("Informe o tempo de exame:");
                scanf("%d",&tempoExame);
                Paciente * p = criarPaciente(nome, tempoExame); //Montando struct Paciente
                f = pushF(f,p); //Adicionando na fila
                pi = pushP(pi,p); //Adicionando na Pilha
				l = pushL(l,p);
				
				printf("\n");
                system("pause");
                system("color 07");
                system("cls");
            	
				break;
            case 2:
            	
            	printf("Insira o nome do paciente a ser pesquisado: ");
                scanf("%s", &nome);

              	Paciente * busca = buscarPaciente(f, nome);
              	if(!buscarPaciente(f, nome)){
                    printf("\nO paciente nao se encontra na fila.\n");
                }else{
                	printf("\n       Paciente Encontrado!\n\n");
                	pacDisplay(busca);
				}
              	printf("\n");
                system("pause");
                system("cls");
            	break;
            	
            case 3:
            	
            	printf("Informe o tempo minímo de exame:");
            	scanf("%d",&valor);
            	
            	l = displayPrimeiroMenorTempo(l,valor);
            	
                printf("\n");
                system("pause");
               	system("cls");
            	break;
            case 4:
            	
               	
               	
               	printf("\n");
                system("pause");
               	system("cls");
            	break;
            case 5:
            	system("cls");
            	printf("\n -------------------------");
	            printf("\n|                         |");
	            printf("\n|   1. FILA               |");
	            printf("\n|   2. PILHA              |");
	            printf("\n|   3. LISTA              |");
	            printf("\n|   0. SAIR               |");
	            printf("\n|                         |");
	            printf("\n -------------------------\n >>> ");
	            scanf("%d", &opcaoSub);
	            
	            switch(opcaoSub){
	            	case 1:
	            		exibirFila(f);
	            		
	            		printf("\n");
		               	system("pause");
		               	system("cls");
		               	break;
		            case 2:
		            	exibirPilha(pi);
		               	
						printf("\n");
		               	system("pause");
		               	system("cls");   
						break;
					case 3:
						
						exibirLista(l);
						
						printf("\n");
		               	system("pause");
		               	system("cls");  
		            default:
		            	system("cls");
		            	break;
				}
            	
            	break;
        }

    }while(opcao != 0);
}


