/*Elaborar um editor de recados que dever�o
ser armazenados em arquivos texto. O Editor
dever� contemplar as op��es:
1 - Novo arquivo
2 - Editar arquivo existente
3 - Leitura arquivo existente
0 - Sair
O usu�rio dever� informar o nome do arquivo
que deseja criar/editar/ler. Quando for novo
arquivo - um novo arquivo dever� ser criado,
quando for editar arquivo - o usu�rio poder�
continuar a edi��o a partir do fim do arquivo
e leitura o usu�rio poder� ver o conte�do do
arquivo. Implementar por meio de fun��es */

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//variables
char entrada

//declara��o do ponteiro do arquivo
FILE *arquive;

void new(*arquive) {
	arquive = fopen("arquivo.txt","a");
	
	while((entrada = getche()) != '\r') {
		putc(entrada,arquive);
	}
}

void edit(*arquive) {
	
}

void read(*arquive) {
	
}

void menu() {
	int opcao;
	
	printf("1 - Novo arquivo\n2 - Editar arquivo existente\n3 - Leitura arquivo existente\n0 - Sair");
	printf("Escolha uma op��o: ");
	scanf("%d", &opcao);
	
	switch(opcao) {
		case 1 : {
			//new arquivo
			new(arquive);
			break;
		}
		case 2 : {
			//edit
			
			break;
		}
		case 3 : {
			//read
			
			break;
		}
		case 0 : {
			//exit
			exit(0);
			break;
		}
	}
	
	
}
















