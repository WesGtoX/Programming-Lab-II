/*Exerc�cio:
1 - Utilizando fun��o com passagem de pr�metro por refer�ncia implemente
um algoritmo para ler dois n�meros reais e trocar os valores entre as
vari�veis, assim o valor da primeira vari�vel vai para a segunda e o
valor da segunda vai para a primeira.*/

//libraries
#include <stdio.h>
#include <stdlib.h>
 
void troca(int *a, int *b);

main() {
	//local variables
	int n1, n2;
	
	printf("Digite o primeiro valor: ");
	scanf("%d", &n1);
	
	printf("Digite o primeiro valor: ");
	scanf("%d", &n2);
	
	printf("\nSequencia informada: %d, %d\n\n", n1, n2);
	
	//function troca call
	troca(&n1, &n2);
	
	printf("Nova sequancia: %d, %d\n\n", n1, n2);
	
	return 0;
}

void troca(int *a, int *b) {
	//local variables
	int aux;
	
	aux = *a;
	*a = *b;
	*b = aux;
}
