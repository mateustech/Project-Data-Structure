#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "paciente.h"
#include "fila.h"
#include "pilha.h"
#include "lista.h"

void limpa_buffer(void);

int main(void) {
	setlocale(LC_ALL , "Portuguese");
	
	int opcao,opcaoSub,valor, tempoExame, garanteMovi = 0;
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
            printf("\n|   6. GERAR RELATÓRIO               |");
            printf("\n|   7. AJUDA                         |");
            printf("\n|   0. SAIR                          |");//default
            printf("\n|                                    |");
            printf("\n ------------------------------------\n >>> ");
            scanf("%d", &opcao);
        } while(opcao < 0 || opcao > 7);
		
		limpa_buffer();
        switch(opcao){
            case 1:
            	if(!garanteMovi){
            		
	                printf("Informe o nome do Paciente:");
	                scanf(" %[^\n]s",nome);
	                printf("Informe o tempo de exame:");
	                scanf("%d",&tempoExame);
	                Paciente * p = criarPaciente(nome, tempoExame); //Montando struct Paciente
	                f = pushF(f,p); //Adicionando na fila
				
				}else{
					printf("\t\tATENÇÃO!\n\tA fila ja foi atendida\n\n");
				}
			
				printf("\n");
                system("pause");
                system("color 07");
                system("cls");
            	
				break;
            case 2:
            	
            	printf("Insira o nome do paciente a ser pesquisado: ");
                scanf(" %[^\n]s", &nome);

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
            	if(garanteMovi){
            		printf("Informe o tempo minímo de exame:");
            		scanf("%d",&valor);
            	
            		displayPrimeiroMenorTempo(l,valor);
				}else{
					system("color 04");
					printf("\nPrimeiro Atenda a Fila do Hospital.\n");
				}
            	
            	
                printf("\n");
                system("pause");
                system("color 07");
               	system("cls");
               	limpa_buffer();
            	break;
            case 4:
            	if(!garanteMovi){
            		pi = move_Fila_Pilha(f,pi);
               		l = move_Pilha_Lista(pi,l);
               		
               		f = mapearNo(f);
               		garanteMovi++;
					printf("\n\nFila atendida com sucesso.\nJa pode gerar os relatorios.\n");
				}else{
					system("color 04");
					printf("\t\tATENÇÃO!\n\tA fila ja foi atendida\n\n");
				}
               	
               	
               	
               	printf("\n");
                system("pause");
                system("color 07");
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
	            		
	            		
		               	break;
		            case 2:
		            	if(garanteMovi){
		            		exibirPilha(pi);
						}else{
							system("color 04");
							printf("Você ainda não moveu os dados.\n");
						}
		            	
		            
						break;
					case 3:
						if(garanteMovi){
							exibirLista(l);
						}else{
							system("color 04");
							printf("Você ainda não moveu os dados.\n");
						}
						
						break;
		            default:
		            	system("cls");
		            	break;
				}
            	printf("\n");
		        system("pause");
		        system("color 07");
		        system("cls");  
		       
            	break;
            case 6:
            	
            	GerarArquivo(l);
            	printf("\n\nArquivo Relatorio.txt Gerado com Sucesso!\n\n");
            	
            	
            	printf("\n");
                system("pause");
               	system("cls");
               	
            	break;
            case 7:
            	system("cls");
            	printf("\n ------------------------  AJUDA  -------------------------");
           		printf("\n|                                                          |");
	            printf("\n| Para um Funcionamento Perfeito do Sistema, primeiro deve |");
				printf("\n| cadastrar pacientes e em paralelo pode buscar pacientes  |");
				printf("\n| na fila, apos esta etapa podemos atender a fila do       |");
				printf("\n| hospital e em seguida pesquisar qual o proximo paciente  |");
				printf("\n| a ser atendido, depois disso ja pode gerar relatorio em  |");
				printf("\n| .txt e a qualquer momento voce pode imprimir na tela a   |");
				printf("\n| fila, pilha e lista.                                     |");
           		printf("\n|                                                          |");		
	            printf("\n ----------------------------------------------------------");		
	            printf("\n");
                system("pause");
               	system("cls");
		        break;
            
        }

    }while(opcao != 0);
}

void limpa_buffer(void){
	int valorLido;
    do{
        valorLido = getchar();
    }while ((valorLido != '\n') && (valorLido != EOF));
}


