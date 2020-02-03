#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "paciente.h"
#include "fila.h"
#include "pilha.h"
#include "lista.h"
#include "interacao.h"
#include "leitura.h"

//opcoes do menu principal
#define N_OPCOES '8'
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

//opcoes do do submenu de impressao
#define N_OPCOES_SUBMENU 4
#define OPCAO1_SUBMENU '1'
#define OPCAO2_SUBMENU '2'
#define OPCAO3_SUBMENU '3'
#define OPCAO4_SUBMENU '4'

int main(void) {
	setlocale(LC_ALL , "Portuguese");
	
	unsigned char op1, op2;
	unsigned int saida1=0, saida2;
	int tempoExame, garanteMovi = 0;
	char* nome;
	
	//criacao das estruturas de dados usadas no programa
	Fila * fila = novaFila();
	Pilha* pilha = novaPilha();
	Lista* lista = novaLista();
	
	
	do{
		mensagemAbertura();
        menuPrincipal();
        op1=leOpcao(OPCAO1, OPCAO1+N_OPCOES-1);
        limpaTela();
        switch(op1){
            case OPCAO1:
            	printf("[CADASTRO DE PACIENTE]\n\n\n");
            	if(!garanteMovi){
	                nome = leNome();
	                tempoExame = leTempo();
	                Paciente * p = criarPaciente(nome, tempoExame);
	                
	                Paciente* p_aux = ultimoPacienteDaFila(fila);
	                
	                if(filaVazia(fila)){
	                	fila = pushFila(fila,p);
	                	system("color 02");
	                	printf("\nPaciente adicionado com sucesso.\n\n\n");
					}
					else if(compara(p_aux, p)){
						fila = pushFila(fila,p);
						system("color 02");
						printf("\nPaciente adicionado com sucesso.\n\n\n");
					}
					else{
						liberaPaciente(p);
						system("color 04");
						printf("\n\tATENÇÃO!\n");
						printf("Tempo de exame menor do que o último inserido.\n");
						printf("Não é possível adicionar o paciente.\n\n\n");
					}
				}else{
					system("color 04");
					printf("\tATENÇÃO!\n");
					printf("A fila já foi atendida.\n");
					printf("Cadastro de pacientes inativo.\n\n\n");
				}
				
				system("pause");
                system("color 07");
				limpaTela();
				break;
            case OPCAO2:
            	printf("[BUSCA DE PACIENTE]\n\n\n");
            	if(!garanteMovi){
            		nome = leNome();

              		Paciente * paciente = buscarPaciente(fila, nome);
              		if(!paciente){
                    	printf("\nO paciente nao se encontra na fila.\n\n\n");
                	}else{
                		system("color 02");
						printf("\nPaciente encontrado:\n");
                		pacDisplay(paciente);
                		printf("\n\n");
					}	
				}
				else{
					system("color 04");
					printf("\tATENÇÃO!\n");
					printf("A fila já foi atendida.\n");
					printf("Busca de paciente inativa.\n\n\n");
				}
				
                system("pause");
                system("color 07");
				limpaTela();
            	break;
            case OPCAO3:
            	printf("[BUSCA DE PACIENTE POR TEMPO]\n\n\n");
            	if(garanteMovi){
            		tempoExame = leTempo();
            		
            		displayPrimeiroMenorTempo(lista, tempoExame);
				}else{
					system("color 04");
					printf("\tATENÇÃO!\n");
					printf("\nA fila do hospital ainda não foi atendida.\n\n\n");
				}
            	
                system("pause");
                system("color 07");
               	limpaTela();
            	break;
            case OPCAO4:
            	printf("[ATENDENDO A FILA DO HOSPITAL]\n\n\n");
            	if(!garanteMovi){
            		pilha = moveFilaPraPilha(fila,pilha);
               		lista = movePilhaPraLista(pilha,lista);
               		
               		fila = liberarFila(fila);
               		garanteMovi = 1;
               		
               		system("color 02");
					printf("\nFila atendida com sucesso.\n");
					printf("Geração do relatório liberada.\n\n\n");
				}else{
					system("color 04");
					printf("\tATENÇÃO!\n");
					printf("\nA fila já foi atendida.\n\n");
				}
				
                system("pause");
                system("color 07");
               	limpaTela();
            	break;
            case OPCAO5:
            	limpaTela();
	            saida2 = 0;
				do{	
					mensagemAbertura();
					submenuImpressao();
					op2=leOpcao(OPCAO1_SUBMENU, OPCAO1_SUBMENU+N_OPCOES_SUBMENU-1);
					limpaTela();
	            	switch(op2){
	            		case OPCAO1_SUBMENU:
							printf("[EXIBINDO A FILA]\n\n\n");
							if(filaVazia(fila)){
								printf("Fila vazia.\n\n\n");
							}
							else{
								exibirFila(fila);	
							}
	            			
	            			system("pause");
		        			system("color 07");
		        			limpaTela();
							break;
		            	case OPCAO2_SUBMENU:
		            		printf("[EXIBINDO A PILHA]\n\n\n");
		            		if(garanteMovi){
		            			if(pilhaVazia(pilha)){
		            				printf("Pilha vazia\n\n\n");
								}
								else{
									exibirPilha(pilha);	
								}
							}else{
								system("color 04");
								printf("\tATENÇÃO!\n");
								printf("A fila do hospital ainda não foi atendida.\n\n\n");
							}
							
							system("pause");
		        			system("color 07");
		        			limpaTela();
							break;
						case OPCAO3_SUBMENU:
							printf("[EXIBINDO A LISTA]\n\n\n");
							if(garanteMovi){
								if(listaVazia(lista)){
									printf("Lista vazia.\n\n\n");								
								}
								else{
									exibirLista(lista);	
								}
							}else{
								system("color 04");
								printf("\tATENÇÃO!\n");
								printf("A fila do hospital ainda não foi atendida.\n\n\n");
							}
							
							system("pause");
		        			system("color 07");
		        			limpaTela();
							break;
		            	case OPCAO4_SUBMENU:
		            		saida2 = 1;
		            		mensagemDespedida("Encerrando a impressão. Ate breve...");
		            		
							system("pause");
		        			system("color 07");
		        			limpaTela();
		            		break;
						default:
		            		printf("Este programa possui um bug\n");
							return 1;
					}
				}while(!saida2);
            	break;
            case OPCAO6:
            	printf("[GERANDO RELATÓRIO]\n\n\n");
				if(garanteMovi){
            		gerarArquivo(lista);
					system("color 02");
					printf("\nRelatório gerado com sucesso.\n\n\n");
				}
				else{
					system("color 04");
					printf("\tATENÇÃO!\n");
					printf("A fila do hospital ainda não foi atendida.\n\n\n");
				}
            
                system("pause");
                system("color 07");
		        limpaTela();
            	break;
            case OPCAO7:
            	limpaTela();
            	mensagemAjuda();
            	
                system("pause");
               	limpaTela();
		        break;
		    case OPCAO8:
		    	saida1 = 1;
		    	mensagemDespedida("Encerrando o programa. Ate breve...");
		    	break;
		    default:
				printf("Este programa possui um bug\n");
				return 1;
        }

    }while(!saida1);
    
    //liberando a pilha
	pilha = liberarPilha(pilha);
    if(pilhaVazia(pilha)){
    	printf("Pilha liberada\n");
	}
	
	//liberando a lista
	lista = liberarFila(lista);
    if(listaVazia(lista)){
    	printf("Lista liberada\n");
	}
	
    return 0;
}
