/*Algoritmo para receber um conjunto de  números inteiros e mostrar
qual o menor e o maior número por meio de uma única função utilizando
passagem por referência*/

//libraries
#include <stdio.h>
#include <stdlib.h>

//declaração do protótipo da função maxmin()
int maxmin(int n, int *maximo, int *minimo);

//main function
main() {
	//local variables
	int qtd, maior, menor;
	
	//data entries
	printf("Informe a quantidade de valores: ");
	scanf("%i", &qtd);
	
	//function maxmin call
	if(maxmin(qtd, &maior, &menor) == 1) {
		printf("\nMaior = %i\nMenor = %i\n\n", maior, menor);
	}
	else {
		printf("\nSequenca vazia...");
	}
	
	system("pause");
}

//maxmin function
int maxmin(int n, int *maximo, int *minimo) {
	
	//local variables
	int numero, i;
	
	//validar n <= 0
	if(n <= 0) {
		return 0;
	}
	
	//apenas um número
	printf("Informe um numero: ");
	scanf("%i", minimo);
	*maximo = *minimo;
	
	//n números
	for(i=2; i <= n; i++) {
		printf("Informe um numero: ");
		scanf("%i", &numero);
		
		if(numero > *maximo) {
			*maximo = numero;
		}
		else if(numero < *minimo) {
			*minimo = numero;
		}
	}
	return 1;
}
