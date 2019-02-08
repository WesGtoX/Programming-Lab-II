/*Elaborar um editor de recados que deverão
ser armazenados em arquivos texto. O Editor
deverá contemplar as opções:
1 - Novo arquivo
2 - Editar arquivo existente
3 - Leitura arquivo existente
0 - Sair
O usuário deverá informar o nome do arquivo
que deseja criar/editar/ler. Quando for novo
arquivo - um novo arquivo deverá ser criado,
quando for editar arquivo - o usuário poderá
continuar a edição a partir do fim do arquivo
e leitura o usuário poderá ver o conteúdo do
arquivo. Implementar por meio de funções */

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//variables
char entrada

//declaração do ponteiro do arquivo
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
	printf("Escolha uma opção: ");
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
















