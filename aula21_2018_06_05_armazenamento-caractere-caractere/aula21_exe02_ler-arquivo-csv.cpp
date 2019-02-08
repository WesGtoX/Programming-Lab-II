/*Exerc�cio
1 - Criar um programa para ler o arquivo aluno.csv e mostrar seu conte�do com a seguinte formata��o:
nome
email
status
---------------------
nome
email
status*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

//declara��o do ponteiro para o arquivo
FILE *pontarq;

//fun��o ler()
void ler() {
	//declara��o da vari�vel
	char caractere, teste;
	
	//abertura do arquivo para leitura
	if((pontarq=fopen("alunos.csv","r+b")) == NULL) {
		printf("Erro ao abrir o arquivo...");
		system("pause");
		exit(0);
	}
	//teste=fgetc(pontarq);
	while((teste=fgetc(pontarq)) != EOF) {
	//while(teste != EOF) {

		printf("Nome: ");
		while((caractere=fgetc(pontarq)) != ';' && caractere != '\n') {
			printf("%c", caractere);
		}

		printf("\nE-mail: ");
		while((caractere=fgetc(pontarq)) != ';' && caractere != '\n') {
			printf("%c", caractere);
		}
	
		printf("\nStatus: ");
		while((caractere=fgetc(pontarq)) != ';' && caractere != '\n') {
			printf("%c", caractere);
		}
		
		printf("---------------------\n");
	}
	
	//fechar o arquivo
	fclose(pontarq);
}

main() {
	setlocale(LC_ALL, "Portuguese");
	ler();
}
