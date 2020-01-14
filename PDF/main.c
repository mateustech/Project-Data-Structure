#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "paciente.h"
#include "fila.h"

#define MSG "Paciente Adicionado Com Sucesso!"

int main() {
	setlocale(LC_ALL , "Portuguese");
	
	int opcao, tempoExame;
	char nome[50];
	
	Fila * f = nova_fila();//fila.h
	
	do{
        do{
        	
            printf("\n#####################################");
            printf("\n*                                   *");
            printf("\n|   1. CADASTRAR PACIENTE           |");
            printf("\n*   2. BUSCAR PACIENTE              *");
            printf("\n|   3. PRÓXIMO PACIENTE             |");
            printf("\n*   4. VERIFICAR TAMANHO DA FILA    *");
            printf("\n|   5. IMPRIMIR DADOS               |");
            printf("\n*   0. SAIR                         *");
            printf("\n|                                   |");
            printf("\n#####################################\n >>> ");
            scanf("%d", &opcao);
        } while(opcao < 0 || opcao > 5);
		
        switch(opcao){
            case 1:
            	
                printf("Informe o nome do Paciente:");
                scanf("%s",nome);
                printf("Informe o tempo de exame:");
                scanf("%d",&tempoExame);
                Paciente * p = criarPaciente(nome, tempoExame);
                f = push(f,p);
                printf("\n%s\n",MSG);
                
				printf("\n");
                system("pause");
                system("cls");
            	
				break;
            case 2:
            	
            	printf("Insira o nome do paciente a ser pesquisado: ");
                scanf("%s", &nome);

              	buscarPaciente(f, nome);
              	printf("\n");
                system("pause");
                system("cls");
            break;
            case 3:
            	
                printf("\n");
                system("pause");
               	system("cls");
            	break;
            case 4:
               
            	break;
            case 5:
            	
            	exibirFila(f);
            	
            	printf("\n");
               	system("pause");
               	system("cls");
               	
            	break;
        }

    }while(opcao != 0);
}


