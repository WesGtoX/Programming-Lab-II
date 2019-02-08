/*Programa para manipular vetores utilizando função */

//libraries
#include <stdio.h>
#include <stdlib.h>

//constant
#define MAX 10

//declaração da função inserir no vetor
void inserir(int vetor[], int tamanho) {
	int i;
	for(i=0; i<tamanho; i++) {
		printf("Informe um numero inteiro: ");
		scanf("%i", &vetor[i]);
	}
}

//declaração da função mostrar dados do vetor
void mostrar(int vetor[], int tamanho) {
	int i;
	for(i=0; i<tamanho; i++) {
		printf("%i ", vetor[i]);
	
	}
	printf("\n\n");
}

//main function
main() {
	//local variables
	int numeros[MAX];
	
	//function call for register vector numbers
	inserir (numeros,MAX);
	
	//function call for show vector numbers
	mostrar(numeros, MAX);
	
	system("pause");
}
