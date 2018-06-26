//Mediana
/*
- Valor que separa um conjunto de dados em duas partes iguais.
- 1� Ordenar o conjunto de dados.
- 2� Encontrar a posi��o mediana.
	Equa��o: �mpar: (n + 1) / 2 - Par: n / 2 e (n + 2) / 2)

- 3� Valor mediano: �mpar: valor que ocupa a posi��o mediana
	Par: m�dia dos valores que ocupam as posi��es mediana */
	
/* Exerc�cio: implementar um programa para receber at� 10 n�meros
inteiros e mostrar qual � o valor mediano */

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
