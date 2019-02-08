/*Algoritmo para receber um conjunto de  n�meros inteiros e mostrar
qual o menor e o maior n�mero por meio de uma �nica fun��o utilizando
passagem por refer�ncia*/

//libraries
#include <stdio.h>
#include <stdlib.h>

//declara��o do prot�tipo da fun��o maxmin()
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
	
	//apenas um n�mero
	printf("Informe um numero: ");
	scanf("%i", minimo);
	*maximo = *minimo;
	
	//n n�meros
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
