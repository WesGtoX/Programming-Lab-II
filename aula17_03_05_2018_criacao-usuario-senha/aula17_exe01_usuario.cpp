/*1 - Implementar a função cadastrar cliente que deverá contemplar no cadastro os 
atributs: nome, data de nascimento, e-mail e telefone. (não pode haver nomes repetidos)
2 - Implementar a função listar clientes */

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//struct
typedef struct usuario {
	char nome[30];
	char login[15];
	char senha[10];
	int perfil;
} usuario;

usuario usuarios;

typedef struct cliente {
	char nome[30];
	char temp[30];
	char data_nasc[10];
	char email[30];
	char fone[15];
} cliente;

cliente clientes;

int cl;
//prototipo funcao cad_usuario
//void cad_usuario();

//ponteiro para o arquivo
FILE *arquivo;
FILE *arquivo2;

//register user function
void cad_usuario(int chamada) {
	system("cls");
	
	//abrir arquivo para gravação modo binário
	arquivo = fopen("usuario.txt","ab");
	
	printf("Informe o nome do usuario: ");
	fflush(stdin);
	gets(usuarios.nome);
	
	printf("Informe o login do usuario: ");
	fflush(stdin);
	gets(usuarios.login);
	
	printf("Informe a senha do usuario: ");
	fflush(stdin);
	gets(usuarios.senha);
	
	if(chamada == 0) {
		usuarios.perfil = 1;
	}
	else {
		printf("\n1 - Administrador\n2 - Gerente\n3 - Tecnico\n\nInforme o perfil: ");
		scanf("%i", &usuarios.perfil);
	}
	
	//gravar em arquivo
	fwrite(&usuarios, sizeof(usuarios),1,arquivo);
	
	//fechar o arquivo
	fclose(arquivo);
}

void cad_clientes() {
	system("cls");
	
	//abrir arquivo para gravação modo binário
	arquivo2 = fopen("cliente.txt","ab");
	
	printf("Informe o nome do cliente: ");
	fflush(stdin);
	gets(clientes.temp);
	
	while(fread(&clientes, sizeof(clientes), 1, arquivo2) == 1) {
		if(strcmp(clientes.temp, clientes.nome) == 0) {
			printf("\nNome já existente...\n\n");
			fclose(arquivo2);
			//menu(perfil);
		}
		else {
			strcpy(clientes.nome,clientes.temp);
		}
	}		
		printf("Informe a data de nascimento do cliente: ");
		fflush(stdin);
		gets(clientes.data_nasc);
		
		printf("Informe o e-mail do cliente: ");
		fflush(stdin);
		gets(clientes.email);
		
		printf("Informe o telefone do cliente: ");
		fflush(stdin);
		gets(clientes.fone);
	
	//gravar em arquivo
	fwrite(&clientes, sizeof(clientes),1,arquivo2);
	
	//fechar o arquivo
	fclose(arquivo2);
}

void show_clientes() {
	system("cls");
	
	//abrir arquivo para leitura
	arquivo2 = fopen("cliente.txt","r");
	
	//local variable
	int i;
	
	while(fread(&clientes, sizeof(clientes), 1, arquivo2) == 1) {
		printf("Nome: %s\n",clientes.nome);
		printf("Data de nascimento: %s\n",clientes.data_nasc);
		printf("E-mail: %s\n",clientes.email);
		printf("Telefone: %s\n\n",clientes.fone);
	}
	
	system("pause");
	
	//fechar arquivo
	fclose(arquivo2);
}

//menu function
void menu(int perfil) {
	system("cls");
	
	//local variables
	int opcao;
	printf("*** MENU ***");
	
	printf("\n1 - Consultar clientes");
	
	if(perfil == 1 || perfil == 2) {
		printf("\n2 - Inserir clientes");
	}
	if(perfil == 1) {
		printf("\n3 - Cadastrar usuario");
	}
	printf("\n4 - Listar clientes");
	printf("\n0 - Sair");
	printf("\n\nEscolha uma opcao: ");
	//printf("\n1 - Cadastrar usuario\n2 - Inserir clientes\n3 - Consultar clientes\n0 - Sair\n\nEscolha uma opcao: ");
	scanf("%i", &opcao);
	
	if(opcao == 0) {
		exit(0);
	}
	else if(opcao == 1) {
		menu(perfil);
	}
	else if(opcao == 2 && (perfil == 1 || perfil == 2)) {
		cad_clientes();
		menu(perfil);
	}
	else if(opcao == 3 && perfil == 1) {
		cad_usuario(3);
		menu(perfil);
	}
	else if (opcao == 4) {
		show_clientes();
		menu(perfil);
	}
	else {
		printf("\nOpcao invalida...\n\n");
		system("pause");
		menu(perfil);
	}
	/*
	switch(opcao) {
		case 1 : {
			menu(perfil);
			break;
		}
		case 2 : {
			menu(perfil);
			break;
		}
		case 3 : {
			cad_usuario(3);
			break;
		}
		case 0 : {
			exit(0);
			break;
		}
		default : {
			printf("\n\nOpcao invalida...");
			system("pause");
			menu(perfil);
			break;
		}
	}*/
}

//login funcion
void login() {
	
	//variaveis auxiliares
	char auxlogin[15], auxsenha[10];
	int flag = 0;
	
	//abrir o arquivo para leitura ou gravação
	if((arquivo = fopen("usuario.txt","rb")) == NULL) {
		printf("Primeiro acesso... Cadastrar usuario admin\n\n");
		system("pause");
		cad_usuario(0);
	}
	else {
		printf("Informe o login: ");
		fflush(stdin);
		gets(auxlogin);
		
		printf("Informe a senha: ");
		fflush(stdin);
		gets(auxsenha);
		
		while(fread(&usuarios,sizeof(usuarios),1,arquivo) == 1) {
			if((strcmp(usuarios.login,auxlogin) == 0) && (strcmp(usuarios.senha,auxsenha) == 0)) {
				menu(usuarios.perfil);
				flag = 1;
			}
		}
		if(flag == 0) {
			printf("Usuario nao encontrado\n\n");
			system("pause");
		}
	}
}

//main function
main() {
	login();
}
