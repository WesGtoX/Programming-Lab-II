/*Algoritmo para exemplificar a manipulacao de string*/

//declaracao das bibliotecas
#include <stdio.h>
#include <stdlib.h>
//biblioteca para podermos chaamar as funcoes para manipulacao de string
#include <string.h>
#include <conio.h>

//declaracaoo das variaveis
char nome[30], nomemax[30];
int i, idade, maxidade=0;

//declaracao da função principal
main() {
	
	//estrutura da funcao principal
	for(i=1; i<=5; i++) {
		//entrada de dados
		printf("Informe o nome da pessoa: ");
		//limpar o buffer
		fflush(stdin);
		//funcao gets() - permite a entrada de string
		gets(nome);
		printf("Informe a idade da pessoa: ");
		scanf("%i", &idade);
		
		//verificar a idade
		if(idade >= maxidade) {
			maxidade = idade;
			/*funcao strcpy() (strig copy) = copia uma string
			para outra - sitaxe: strcpy(string1, string2) */
			strcpy(nomemax,nome);	
		}
	}
	//saida de dados
	printf("A pessoa mais velha chama-se %s", nomemax);
	printf("\ntem %i anos\n\n", maxidade);
	
	system("pause");
}
