/*Algoritmo para receber dois numeros inteiros e a op��o de calculo de raiz 
quadrada ou exponencia��o. Ap�s retornar o valor do calculo o usu�rio ter� 
novamente a possibilidade de escolher novamente valores e o tipo de calculo*/

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

//variables
int opcao;
char control;

//menu function
int menu() {
	system("cls");
	printf(":::::. RAIZ QUADRADA E EXPONENCIA��O .:::::\n\n");
	printf("\n1 - Raiz Quadrado\n2 - Exponencia��o\n\nEscolha uma op��o: ");
	scanf("%i", &opcao);
	return opcao;
}

void header() {
	system("cls");
	if(opcao == 1) {
		printf(":::::. RAIZ QUADRADA .:::::\n\n");
	}
	else {
		printf(":::::. EXPONENCIA��O .:::::\n\n");
	}
}

//main function
main() {
	
	//aceitar caracteres especiais em pr-br
	setlocale(LC_ALL,"portuguese");
	
	//local variables
	int calculo;
	float n=0, number, raiz=0, expo=0;
	
	
	//data entry
	do {
		calculo = menu();
		
		switch(calculo) {
			case 1: {
				system("cls");
				header();
				
				printf("\nInforme um n�mero: ");
				scanf("%f", &n);
				printf("Informe o �ndice da raiz: ");
				scanf("%f", &raiz);
				number = pow(n,1.0/raiz);
				
				printf("-------------------------");
				printf("\n\nO c�lculo da raiz de %.f e = %.2f \n\n", n,number);
				break;
			}
			
			case 2 : {
				system("cls");
				header();
				
				printf("\nInforme um n�mero: ");
				scanf("%f", &n);
				printf("Informe o valor do expoente: ");
				scanf("%f", &expo);
				number = pow(n,expo);
				
				printf("-------------------------");
				printf("\n\nO c�lculo exponencial de %.f e = %.2f \n\n", n,number);
				break;
			}
		}
		
		printf("\nOutro c�lculo? <S/N>: ");
		control = getche();
		
	} while(toupper(control)=='S');
	system("pause");
}
