/* Utilizando estrutura de dados e funções (obrigatória), crie um programa utilizando a linguagem C 
para armazenar as despezas hospitalares de um paciente, sendo que para cada despeza armazena-se o código 
do medicamento, o nome, a quantidade e o valor. 
O usuário decidirá quando parar de informar as despesas, todavia terá no máximo 50 despesas. 
Criar também uma função para listar as despesas realizadas em ordem alfabética, 
a quantidade total de remédiose o valor total das despesas */

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//constant
#define MAX 50

//data struct
struct gastos {
	int codigo;
	char nome[30];
	int qtd;
	float valor;
};
typedef struct gastos med;

//global variables
int qtd_total, med_qtd;
float valor_total;

//despeza function
void despeza(gastos med[]) {
	//local variables
	int i;
	char control;
	
	//data entry
	do {
		system("cls");
		
		printf("Digite o codigo do medicamento: ");
		scanf("%i", &med[i].codigo);
		
		printf("Digite o nome do medicamento: ");
		fflush(stdin);
		gets(med[i].nome);
		
		printf("Digite a quantidade do medicamento: ");
		scanf("%i", &med[i].qtd);
		
		printf("Digite o valor do medicamento: ");
		scanf("%f", &med[i].valor);
		
		//total sum
		qtd_total += med[i].qtd;
		valor_total += med[i].qtd * med[i].valor;
		
		med_qtd++;
		
		if(i <= MAX) {
			printf("\nDeseja adicionar outro? <S/N> ");
			control = getche();
			i++;
		}
		else {
			system("cls");
			printf("O seu limite foi estourado!!!");
			control = 'N';
			system("pause");
		}
	}while(toupper(control) == 'S');
}

//show_all function
void show_all(gastos med[]) {
	system("cls");
	
	int i;
	
	for(i=0; i <= med_qtd; i++) {
		printf("\nCodigo: %i", med[i].codigo);
		printf("\nNome: %s", med[i].nome);
		printf("\nQtd: %i", med[i].qtd);
		printf("\nValor: %.2f\n", med[i].valor);
	}
	printf("\nTotal de Remedios: %i", qtd_total);
	printf("\nValor Total: %f", valor_total);
	
	system("pause");
	
}

//menu function
void menu() {
	system("cls");
	
	//local variables
	int opcao;
	
	//struct data
	gastos med[MAX];
	
	printf("1 - Adicionar Despesa\n2 - Mostrar Tudo\n0 - Sair\n\n");
	printf("Escolha uma opcao: ");
	scanf("%i", &opcao);
	
	switch(opcao) {
		case 1 : {
			despeza(med);
			menu();
			break;
		}
		case 2 : {
			//show_all();
			menu();
			break;
		}
		case 0 : {
			exit(1);
			break;
		}
	}
	
}

//main function
main() {
	
	menu();
}
