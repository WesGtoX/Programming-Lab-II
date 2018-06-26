/*Algoritmo para receber informações por meio 
de teclado e guardá-las caractere por caractere 
em arquivo */

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//variables
char entrada;

//declaração do ponteiro do arquivo
FILE *pontarq;

//main function
main() {
	//abertura do arquivo em modo texto para gravação
	pontarq = fopen("arquivo.txt","a");
	
	//entrada de dados e gravação no arquivo
	// \r - Enter
	while((entrada = getche()) != '\r') {
		putc(entrada,pontarq);	
	}
	
	//fechamento do arquivo
	fclose(pontarq);
}
