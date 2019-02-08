/*Elaborar um programa para cadastrar, alterar e listar em ordem alfabética os moradores
de um condomínio com 12 apartamentos. O programa deve atender ao seguinte escopo:
	
1 - Ter um menu para as opções mencionadas, mais a opção sair;
2 - Os dados de cada apartamento são: 
	- Número do apartamento;
	- Nome do morador;
	- CPF do morador
	- % da taxa de condomínio;
3 - Não deve permitir cadastrar número de apartamento repetido;
4 - Utilizar funções.*/

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//constant
#define MAX 12

struct condominio {
	int number;
	char nome[30];
	char cpf[14];
	float taxa;
};
typedef struct condominio apt;

//global variables
int i=0, j=0;

void add(apt apart[]) {
	system("cls");
	
	//local variables
	char control;
	int k=0,n=0, apartamento;

	do {
		system("cls");
		
		//adicionar morador
		if(j < MAX) {			
			printf("Digite o numero de um apartamento vazio: ");
			scanf("%i", &apartamento);
			
			//verificar se apartamento está ocupado
			for(k=0; k < MAX; k++) {
				for(n=0; n < MAX; n++) {
					if(apart[k].number == apartamento) {
						printf("ESSE APARTAMENTO JA ESTA OCUPADO!!!\n\n");
						
						printf("Digite o numero de um apartamento vazio: ");
						scanf("%i", &apartamento);
						k = 0;
					}
				}
			}
			apart[j].number = apartamento;
			
			printf("Digite o nome do morador: ");
			fflush(stdin);
			gets(apart[j].nome);
			
			printf("Digite o CPF do morador: ");
			fflush(stdin);
			gets(apart[j].cpf);
			
			apart[j].taxa = 10.00;
			
		//===============================================
			printf("\nNumero: %i\n", apart[j].number);
			printf("Nome: %s\n", apart[j].nome);
			printf("CPF: %s\n", apart[j].cpf);
			printf("Taxa: %.2f%%\n\n", apart[j].taxa);
		//===============================================
			
			i++;
			j++;
			
			printf("\nDeseja adicionar outro? <S/N> ");
			control = getche();
		}
		else {	//mostrar mensagens que todos os apartamentos estão ocupados
			system("cls");
			printf("NAO TEM APARTAMENTOS DISPONIVEL!!!\n\n");
			control = 'N';
			system("pause");
		}
	}while(toupper(control) == 'S');
}

//change values
void change(apt apart[]) {
	system("cls");
	
	//local variables
	int dados;
	
	//alterar dados de morador
	printf("Informe o numero do apartamento do morador que deseja alterar os dados: ");
	scanf("%i", &dados);
	
	for(i=0; i < MAX; i++) {
		if(apart[i].number == dados) {
			printf("\nDigite o nome do morador: ");
			fflush(stdin);
			gets(apart[i].nome);
			
			printf("Digite o CPF do morador: ");
			fflush(stdin);
			gets(apart[i].cpf);
			
			apart[i].taxa = 10.00;
		}
	}
	
	printf("\n");
	system("pause");
}

//show ordered
void show_order(apt apart[]) {
	system("cls");
	
	//local variables
	int m, aux1;
	char auxc1[30], auxc2[30];
	float auxf;
	
	if(j == 0) {
		printf("NAO HA MORADORES NESSE CONDOMINIO!!!\n\n");
	}
	
	for(i=0; i < j; i++) {
		for(m=i+1; m < j; m++) {
			if(strcmp(apart[i].nome,apart[m].nome) > 0) {
				aux1 = apart[i].number;
				strcpy(auxc1,apart[i].nome);
				strcpy(auxc2,apart[i].cpf);
				auxf = apart[i].taxa;
				
				apart[i].number = apart[m].number;
				strcpy(apart[i].nome,apart[m].nome);
				strcpy(apart[i].cpf,apart[m].cpf);
				apart[i].taxa = apart[m].taxa;
				
				apart[m].number = aux1;
				strcpy(apart[m].nome,auxc1);
				strcpy(apart[m].cpf,auxc2);
				apart[m].taxa = auxf;
			}
		}
	}
	
	for(i=0; i < j; i++) {
		printf("Numero do Apartamento: %i\n", apart[i].number);
		printf("Nome do Morador: %s\n", apart[i].nome);
		printf("CPF do Morador: %s\n", apart[i].cpf);
		printf("Taxa de Condominio: %.2f%%\n\n", apart[i].taxa);
	}	
	
	system("pause");
}

//menu
void menu(apt apart[]) {
	system("cls");
	
	//local variables
	int opcao;
	
	printf("1 - Adicionar\n2 - Alterar\n3 - Listar em Ordem Alfabetica\n0 - Sair\n\n");
	printf("Escolha uma opcao: ");
	scanf("%i", &opcao);
	
	switch(opcao) {
		case 1 : {
			//add
			add(apart);
			menu(apart);
			break;
		}
		case 2 : {
			//change
			change(apart);
			menu(apart);
			break;
		}
		case 3 : {
			//list in alphabetical order
			show_order(apart);
			menu(apart);
			break;
		}
		case 0 : {
			//exit
			printf("\n\tSAINDO...\n");
			exit(0);
			break;
		}
		default : {
			system("cls");
			printf("OPCAO INVALIDA!\n\n");
			system("pause");
			menu(apart);
			break;
		}
	}
}

//main function
main() {
	apt apart[MAX];
	
	menu(apart);
}
