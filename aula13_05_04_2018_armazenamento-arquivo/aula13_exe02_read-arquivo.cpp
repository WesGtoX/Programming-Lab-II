/*Algoritmo para leitura de informa��es
armazenadas em arquivo considerando caracter
por caracter */

//libraries
#include <stdio.h>
#include <stdlib.h>

//variables
char saida;

//main function
main() {
	//declara��o do ponteiro para o arquivo
	FILE *pontarq;
	
	//abertura do arquivo
	if((pontarq = fopen("arquivo.txt","r")) == NULL) {
		printf("\nErro ao abrir o arquivo!\n");
		system("pause");
		exit(0);
	}
	else {
		printf("\nPassou...\n\n");
	}
	
	//leitura do conte�do do arquivo
	while((saida = getc(pontarq)) != EOF) {
		printf("%c", saida);
	}
	system("pause");
	fclose(pontarq); //fechar o arquivo
}
