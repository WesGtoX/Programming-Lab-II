/*Algoritmo para manipulacao de string */

//declaracao das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaracao das variaveis
int i, qtdcaracteres;
char nome[30];

//declaracao da funcao princpal
main() {
	//estrutura de repeticao
	for(i=1; i<=3; i++) {
		printf("Informe o nome da pessoa: ");
		fflush(stdin);
		gets(nome);
		/*funcao strlen() - string length - retora a quantidade de
		caracteres de uma string */
		printf("Nome: %s - %i caracteres\n\n", nome, strlen(nome));
		
	}
	
	system("pause");
}
