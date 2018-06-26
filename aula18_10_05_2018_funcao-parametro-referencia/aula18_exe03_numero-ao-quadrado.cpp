/*Exercício:
2 - Implementar um algoritmo para gerar o quadrado de um número.*/

//libraries
#include <stdio.h>
#include <stdlib.h>

//declaração do protótipo da função quadrado()
void quadrado(int *quad);

//main function
main() {
	
	//local variables
	int numero;
	
	printf("Informe um numero: ");
	scanf("%i", &numero);
	
	//function quadrado call
	quadrado(&numero);
	
	printf("O quadrado do numero informado e %i\n\n", numero);
	
	return 0;
}

void quadrado(int *quad) {
	
	//multiplicação **2
	*quad = *quad * *quad;
}
