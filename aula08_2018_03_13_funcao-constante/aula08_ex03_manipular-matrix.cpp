/* Programa para manipular matrizes utilizando função */

//variables
#include <stdio.h>
#include <stdlib.h>

//constant
#define NLIN 5
#define NCOL 5

//declair function register matrix
void cadastrar(int matrix[NLIN][NCOL], int linha, int coluna) {
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

//main function
main() {
	//declare matrix
	int dados[3][3];
	
	//function call valor matrix
	cadastram(dados,3,3);
}
