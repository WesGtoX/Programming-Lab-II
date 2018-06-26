/* Programa para manipular matrizes utilizando função */

//variables
#include <stdio.h>
#include <stdlib.h>

//constant
#define NLIN 5
#define NCOL 5

//declare function register matrix
void cadastram(int matrix[NLIN][NCOL], int linha, int coluna) {
	//local variables
	int i,j;
	
	//repetition structure
	for(i=0; i<linha; i++) {
		for(j=0; j<coluna; j++) {
			printf("Informe um numero inteiro: ");
			scanf("%i", &matrix[i][j]);
		}
	}
}

int show(int matrix[NLIN][NCOL], int linha, int coluna) {
	//local variables
	int i,j;
	//show matrix
	for(i=0; i<linha;i++) {
		for(j=0; j<coluna; j++) {
			printf("%i ", matrix[i][j]);
		}
	printf("\n");
	}
}

//main function
main() {
	//declare matrix
	int dados[NLIN][NCOL];
	
	//function call valor matrix
	cadastram(dados,3,3);
	
	printf("\n");
	
	//function show matrix
	show(dados,3,3);
	
	//EXERCÍCIO: Implementar função para mostrar os valores de uma matriz
}
