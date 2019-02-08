#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//declara��o do ponteiro para o arquivo
FILE *pontarq;

//fun��o entrada()

void entrada() {
	//declara��o da vari�vel
	char dado, continuar;
	
	//abrir o arquivo para grava��o em modo texto
	pontarq = fopen("arquivo1.txt","ab");
	
	do {
		//estrutua de repeti��o
		while((dado=getche()) != '\r') {
			fputc(dado, pontarq);
		}
		fputc('\n', pontarq);
		
		printf("Outro dados <S|N>? ");
		continuar = getch();
	} while(continuar == 's' or continuar == 'S');
	
	//fechar o arquivo
	fclose(pontarq);
}

//fun��o sa�da
void saida() {
	//declara��o da vari�vel
	char caractere;
	
	//abertura do arquivo para leitura
	if((pontarq=fopen("arquivo1.txt","rb")) == NULL) {
		printf("Erro ao abrir o arquivo...");
		system("pause");
		exit(0);
	}
	while((caractere=fgetc(pontarq)) != EOF) {
		printf("%c", caractere);
	}
	
	//fechar o arquivo
	fclose(pontarq);
}

main() {
	entrada();
	saida();

}
