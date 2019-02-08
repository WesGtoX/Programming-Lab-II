/*Programa para cadastrar os clientes de uma empresa.
Dados do cadastro: Nome; E-mail; Telefone */

//libraryes
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

//struct
struct cliente {
	char nome[30];
	char email[40];
	char telefone[15];
};
struct cliente cliente;

//ponteiro para arquivo
FILE *arquivo;

//inserir() function
void inserir() {
	//local variables
	char resp;
	//abrir o arquivo para gravação
	arquivo = fopen("cliente.txt", "a");
	
	do {
		system("cls");
		printf("Informe o nome do cliente: ");
		fflush(stdin);
		gets(cliente.nome);
		
		printf("Informe o email do cliente: ");
		fflush(stdin);
		gets(cliente.email);
		
		printf("Informe o telefone do cliente: ");
		fflush(stdin);
		gets(cliente.telefone);
		
		//gravar as informações no arquivo
		fwrite(&cliente, sizeof(cliente), 1, arquivo);
		
		printf("\nOutro registro <S/N>: ");
		resp = getche();
	} while(toupper(resp) == 'S');
	
	//fechar o arquivo
	fclose(arquivo);
}

//lsitar() function
void listar() {
	system("cls");
	//abrir o arquivo para leitura
	if((arquivo = fopen("cliente.txt","r")) == NULL) {
		printf("\n\nErro na abertura do arquivo...\n");
		system("pause");
		exit(0);
	}
	
	while(fread(&cliente, sizeof(cliente), 1, arquivo) == 1) {
		printf("Nome: %s", cliente.nome);
		printf("\nE-mail: %s", cliente.email);
		printf("\nTelefone: %s\n\n", cliente.telefone);
	}
	system("pause");
	fclose(arquivo);
}

//menu function
void menu() {
	system("cls");
	
	//local variables
	int opcao;
	
	printf("1 - Cadastrar\n2 - Listar\n0 - Sair");
	printf("\n\nEscolha uma opcao: ");
	scanf("%i", &opcao);
	
	//conditional struct
	switch(opcao) {
		case 1 : {
			inserir();
			menu();
			break;
		}
		case 2 : {
			listar();
			break;
		}
		case 0 : {
			exit(0);
			menu();
			break;
		}
		default : {
			printf("\nOpcao invalida...\n");
			system("pause");
			menu();
			break;
		}
	}
}

//main function
main() {
	
	menu();
}
