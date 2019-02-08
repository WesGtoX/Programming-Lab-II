/*Elaborar um programa para receber números inteiros em duas matrizes 3X3,
realizar a multiplicação das matrizes e mostrar o resultado. */

//libraries
#include <stdio.h>
#include <stdlib.h>

//variables
int A[3][3], B[3][3], C[3][3], mult[3][3];
int i,j, k;

//main function
main() {

	//first matrix data entry
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("Informe um numero inteiro para posicao %iX%i da matriz 1: ",i+1, j+1);
			scanf("%i", &A[i][j]);
		}
	}
	
	//second matrix data entry
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("Informe um numero inteiro para posicao %iX%i da matriz 2: ",i+1, j+1);
			scanf("%i", &B[i][j]);
		}
	}
	
	//multiply of the matrixes
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			for(k=0; k<3; k++) {
				mult[i][j] = A[i][k] * B[k][j] + mult[i][j];
			}
			C[i][j] = mult[i][j];
			mult[i][j] = 0;
		}
	}
	
	//show results
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) 
			printf("%i\t", C[i][j]);
		printf("\n");
	}
	
	printf("\n\n");
	system("pause");
}
