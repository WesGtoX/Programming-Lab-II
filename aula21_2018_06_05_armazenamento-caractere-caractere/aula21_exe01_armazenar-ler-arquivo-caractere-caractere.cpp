#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//declaração do ponteiro para o arquivo
FILE *pontarq;

//função entrada()

void entrada() {
	//declaração da variável
	char dado, continuar;
	
	//abrir o arquivo para gravação em modo texto
	pontarq = fopen("arquivo1.txt","ab");
	
	do {
		//estrutua de repetição
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

//função saída
void saida() {
	//declaração da variável
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
