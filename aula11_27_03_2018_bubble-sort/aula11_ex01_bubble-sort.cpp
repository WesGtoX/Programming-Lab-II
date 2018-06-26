/*Exercício de Ordenação Bubble Sort. Algoritmo para receber 10
numeros inteiros em um vetor e mostrar os números informados em
ordem crescente e em ordem decrescente */

//libraries
#include <stdio.h>
#include <stdlib.h>

//constant
#define MAX 10

//global variables
int i, j;

//data entry function
void entrada(int numero[]) {
	for(i=0; i < MAX; i++) {
		system("cls");
		printf("Informe um numero inteiro: ");
		scanf("%d", &numero[i]);
	}
}

//ordenation function growing
void ordenacres(int numero[]) {
	//local variables
	int aux;
	
	for(i=0; i < MAX; i++) {
		for(j=i+1; j < MAX; j++) {
			if(numero[i] > numero[j]) {
				aux = numero[i];
				numero[i] = numero[j];
				numero[j] = aux;
			}
		}
	}
}

//ordenation function decreasing
void ordenadecres(int numero[]) {
	//local variables
	int aux;
	
	for(i=0; i < MAX; i++) {
		for(j=i+1; j < MAX; j++) {
			if(numero[i] < numero[j]) {
				aux = numero[i];
				numero[i] = numero[j];
				numero[j] = aux;
			}
		}
	}
}

//show function
void show(int numero[]) {
	for(i=0; i < MAX; i++) {
		printf("%i ", numero[i]);
	}
}

//main function
main() {
	//local variables
	int vetor[MAX];
	
	//entrada function call
	entrada(vetor);
	
	//ordenacres function call
	ordenacres(vetor);
	
	printf("\nNumeros em ordem crescente: \n");
	
	//show function call
	show(vetor);

	//ordenadecres function call
	ordenadecres(vetor);
	
	printf("\n\nNumeros em ordem decrescente: \n");

	//show function call
	show(vetor);
}
