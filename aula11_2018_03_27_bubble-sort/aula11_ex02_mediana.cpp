//Mediana
/*
- Valor que separa um conjunto de dados em duas partes iguais.
- 1ª Ordenar o conjunto de dados.
- 2ª Encontrar a posição mediana.
	Equação: Ímpar: (n + 1) / 2 - Par: n / 2 e (n + 2) / 2)

- 3ª Valor mediano: Ímpar: valor que ocupa a posição mediana
	Par: média dos valores que ocupam as posições mediana */
	
/* Exercício: implementar um programa para receber até 10 números
inteiros e mostrar qual é o valor mediano */

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

//show function
void show(int numero[]) {
	for(i=0; i < MAX; i++) {
		printf("%i ", numero[i]);
	}
}

void mediana(int numero[]) {
	int med, par, impar, n;
	
	if(med % 2 != 0) {
		impar = (n + 1) / 2;
	}
	else {
		par = n / 2;
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
	
	//mediana function call
	mediana(vetor);
	
	printf("\nNumeros em ordem crescente: \n");
	
	//show function call
	show(vetor);
}
