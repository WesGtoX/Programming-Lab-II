/* Implementar uma função para gerar a matriz transposta 
de uma matriz informada, a matriz pode ser no máximo 5 x 5 */

//variables
#include <stdio.h>
#include <stdlib.h>

//constant
#define NLIN 5
#define NCOL 5

//declare funcition register matrix
void registM(int matrix[NLIN][NCOL], int l, int c) {
	//local variable
	int i,j;
	
	//repetition structure
	for(i=0; i<l; i++) {
		for(j=0;j<c; j++) {
			printf("Informe o elemento %i x %i da matriz: ",i+1,j+1);
			scanf("%i", &matrix[i][j]);
		}
	}
}

int show(int matrix[NLIN][NCOL], int l, int c) {
	//local variable
	int i,j;
	//show matrix
	for(i=0; i<l; i++) {
		for(j=0; j<c; j++) {
			printf("%i ", matrix[i][j]);
		}
	printf("\n");
	}
}

int transpose(int matrix[NLIN][NCOL], int l, int c) {
	//local variable
	int i,j;
	//show matrix
	for(j=0; j<c; j++) {
		for(i=0; i<l; i++) {
			printf("%i ", matrix[i][j]);
		}
	printf("\n");
	}	
}

//main fucntion
main() {
	//local variable
	int i,j;
	
	//matrix size
	printf("Informe a quantidade de linhas da matriz (Maximo 5): ");
	scanf("%i", &i);
	printf("Informe a quantidade de colunas da matriz (Maximo 5): ");
	scanf("%i", &j);
	printf("\n");
	
	//declare matrix
	int data[NLIN][NCOL];
	
	//funcion call matrix valor
	registM(data,i,j);
	printf("\n");
	
	//function show matrix
	printf("Matriz Informada\n");
	show(data,i,j);
	
	//function show transpose matrix
	printf("\nMatriz Transposta\n");
	transpose(data,i,j);
}
