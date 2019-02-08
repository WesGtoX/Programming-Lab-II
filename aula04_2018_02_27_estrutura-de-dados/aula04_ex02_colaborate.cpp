/*Programa para receber o nome e o valor de 5 colaboradores por meio de 
estrutura de dados, calcular a média dos salários e mostrar o nome dos
colaboradores que possuem remuneração acima da média */

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//type of struct
struct funcionario {
	char nome[30];
	float salario;
};

//variables
struct funcionario colaborador[5];
float media, total=0;
int i;

//main function
main() {
	//Repetition structure for data entry
	for(i=0; i<5; i++) {
		printf("Informe o nome do colaborador: ");
		fflush(stdin);
		gets(colaborador[i].nome);
		printf("Informe o salario do colaborador: ");
		scanf("%f", &colaborador[i].salario);
		total+=colaborador[i].salario;
		system("cls");
	}
	//average calculation
	media = total / 5;
	
	//Replication structure for data output
	for(i=0; i<5; i++) {
		if(colaborador[i].salario > media)
			printf("Nome: %s\n", colaborador[i].nome);
	}
	system("pause");
}
