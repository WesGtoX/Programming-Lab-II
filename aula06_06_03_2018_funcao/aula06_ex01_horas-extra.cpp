/*Algoritmo para receber o valor do saláriom, o total de horas
trabalhadas no mês, a quantidade de horas extras 50%, a quantidade de
horas extras 100% e mostrar o valor que o colaborador deverá receber
considerando seu valor mais o valor das horas extras. O algoritmo deve
ser implementado utilizando função */

//libraries
#include <stdio.h>
#include <stdlib.h>

//function prototype
float valorhe(float vlrhora, float qtdhe, int tipohora);

//main function
main() {
	//local variables
	float salario, totalhmes, horasextras, vlrhe50, vlrhe100;
	
	//data entry
	printf("Informe o valor do salario: R$ ");
	scanf("%f", &salario);
	printf("Informe o total de horas trabalhadas no mes: ");
	scanf("%f", &totalhmes);
	printf("Informe qtd de horas extras 50%: ");
	scanf("%f", &horasextras);
	
	//function call
	vlrhe50 = valorhe(salario/totalhmes,horasextras,50);
	
	printf("Informe qtd horas extras 100%: ");
	scanf("%f", &horasextras);
	
	//function call
	vlrhe100 = valorhe(salario/totalhmes,horasextras,100);
	
	//data output
	printf("\nTotal a receber = R$ %.2f\n\n", salario + vlrhe50 + vlrhe100);
	
	system("pause");
}
//valorhe function
float valorhe(float vlrhora, float qtdhe, int tipohora) {
	return (vlrhora + vlrhora * tipohora / 100) * qtdhe;
}
