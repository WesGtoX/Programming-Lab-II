/*Algoritmo para calcular o fatorial de um número inteiro */

//libraries
#include <stdio.h>
#include <stdlib.h>

//function factorial
int fatorial(int number) {
	//condicional struct
	if(number == 0) {
		return 1;
	}
	else {
		return (number * fatorial(number - 1));
	}
}

//main function
main() {
	//local variables
	int x;
	
	//data entry
	printf("Informe um numero inteiro: ");
	scanf("%i", &x);
	
	//factorial calculation
	printf("\nO fatorial de %i = %i\n\n", x,fatorial(x));
	
	system("pause");
}
