/*Algoritmo para receber informa��es por meio 
de teclado e guard�-las caractere por caractere 
em arquivo */

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//variables
char entrada;

//declara��o do ponteiro do arquivo
FILE *pontarq;

//main function
main() {
	//abertura do arquivo em modo texto para grava��o
	pontarq = fopen("arquivo.txt","a");
	
	//entrada de dados e grava��o no arquivo
	// \r - Enter
	while((entrada = getche()) != '\r') {
		putc(entrada,pontarq);	
	}
	
	//fechamento do arquivo
	fclose(pontarq);
}
