/*Algoritmo para mostrar a soma acumulada de um número inteiro */

//libraries
#include <stdio.h>
#include <stdlib.h>

//function sum
int sum(int number) {
	//condicional struct
	if(number == 1) {
		return 1;
	}
	else {
		return (number + sum(number - 1));
	}
}

//main function
main() {
	//local variables
	int num;
	
	//data entry
	printf("Informe um numero inteiro: ");
	scanf("%i", &num);
	
	printf("\nResultado: %i\n\n", sum(num));
	
	system("pause");
}
