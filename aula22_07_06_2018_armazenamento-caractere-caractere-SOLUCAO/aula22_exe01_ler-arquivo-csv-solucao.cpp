/*Exerc�cio Solu��o
1 - Criar um programa para ler o arquivo aluno.csv e mostrar seu conte�do com a seguinte formata��o:
nome
email
status
---------------------
nome
email
status*/

//libraries
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//variables
char palavra[100], letra[2], caractere;

//declara��o do ponteiro para o arquivo
FILE *pontarq;

//main function
main() {
	setlocale(LC_ALL, "Portuguese");
	
	//abertura do arquivo para leitura
	if((pontarq=fopen("alunos.csv","r")) == NULL) {
		printf("Erro na abertura do arquivo...");
		system("pause");
		exit(0);
	}
	
	while((caractere=fgetc(pontarq)) != EOF) {
		if((caractere == '\n') || (caractere == ';')) {
			printf("%s\n", palavra);
			strcpy(palavra, " ");
			
			if(caractere == '\n') {
				printf("---------------------\n");
			}
		}
		else {
			letra[0] = caractere;
			letra[1] = '\0';
			
			//strcat() - fun��o para concatenar strings
			strcat(palavra,letra);
		}
	}
	printf("%s\n", palavra);
	fclose(pontarq);
	
	system("pause");
}
