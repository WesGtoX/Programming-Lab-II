/* Programa que contempla as operações básicas de uma calculadora */

#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>

//entry data function
float recebe() {
	//declare local variable
	float numero;
	printf("Informe um numero: ");
	scanf("%f", &numero);
}

void menu() {
	//local variable
	int opcao;
	system("cls");
	printf("1 - Soma\n2 - Subtracao\n3 - Divisao\n4 - Multiplicacao\n0 - Sair");
	printf("\n\nEscolha uma opcao: ");
	scanf("%i", &opcao);
	printf("\n");
	
	switch(opcao) {
		case 1 : {
			printf("\nSoma = %1.f\n", soma(recebe(),recebe()));
			system("pause");
			menu();
			break;
		}
		case 2 : {
			printf("\nSubtracao = %1.f\n", subtrai(recebe(),recebe()));
			system("pause");
			menu();
			break;
		}
		case 3 : {
			printf("\nDivisao = %2.f\n", divide(recebe(),recebe()));
			system("pause");
			menu();
			break;
		}
		case 4 : {
			printf("\nMultiplicacao = %1.f\n", multiplica(recebe(),recebe()));
			system("pause");
			menu();
			break;
		}
		case 0 : {
			exit(0);
			break;
		}
		default : {
			printf("\nOpcao Invalida!!!\n");
			system("pause");
			menu();
			break;
		}
	}
}

//main function
main() {
	//declare local variable for test
/*	float num1, num2;
	num1 = recebe();
	num2 = recebe();
	printf("%.1f, %.1f\n", num1, num2);
	system("pause"); */
	
	//call function menu
	menu();
}
