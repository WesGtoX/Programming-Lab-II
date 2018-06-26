/*Programa para receber valores inteiros em duas matrizes 3 x 3,
realizar a soma das matrizes e mostrar a matriz resultante */

//libraries
#include <stdio.h>
#include <stdlib.h>

//variables
int matriz1[3][3], matriz2[3][3], matrizr[3][3], i, j;

//main function
main() {
	//first matrix data entry
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("Informe um numero inteiro para posicao %iX%i da matriz 1: ",i+1, j+1);
			scanf("%i", &matriz1[i][j]);
		}
	}
	
	//second matrix data entry
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("Informe um numero inteiro para posicao %iX%i da matriz 2: ",i+1, j+1);
			scanf("%i", &matriz2[i][j]);
		}
	}
	
	//calculate sum, of the matrixes
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			matrizr[i][j] = matriz1[i][j] + matriz2[i][j];			
		}
	}
	//show results
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) 
			printf("%i\t", matrizr[i][j]);
		printf("\n");
	}
	printf("\n\n");
	system("pause");
}

