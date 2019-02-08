/*Elaborar um programa para gerenciar projetos de pesquisa e atenda as seguintes premissas:
1 - Ser acessado por usuário e senha. A primeira vez definir o usuário administrador.
2 - Gerenciar o acesso as funcionalidade por perfil:
	2.1 - Administrador
	2.2 - Técnico.
3 - Apenas o administrador poderá cadastrar novos usuários.
4 - O programa terá as seguintes funções: 
	Cadastrar usuário, cadastrar projeto de pesquisa, alterar projeto de pesquisa,
	pesquisar projeto de pesquisa por número e listar projeto de pesquisa (ordem alfabética)
5 - O número do projeto de pesquisa deverá ser gerado automaticamente.
6 - Os dados do projeto de pesquisa são:
	número, título, pesquisador responsável, data de início, data fim e valor.*/
	
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

typedef struct projeto {
	int numero;
	char titulo[30];
	char pesquisador[30];
	char data_inicio[10];
	char data_fim[10];
	float valor;
} projeto;

projeto projetos;

//global variables
int n;

FILE *login;
FILE *cadprojetos;

//cadastrar usuario function
void cad_usuario(int chamada) {
	system("cls");
	
	//abrir arquivo para gravação em modo binário
	login = fopen("usuario.txt","ab");
	
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
		printf("\n1 - Administrador\n2 - Tecnico\n\nInforme o perfil: ");
		scanf("%i", &usuarios.perfil);
	}
	
	//gravar em arquivo
	fwrite(&usuarios, sizeof(usuarios),1,login);
	
	//fechar o arquivo
	fclose(login);
}

int sequencia() {
	//local variables
	int numero;
	
	//ponteiro para arquivo
	FILE *sequencia;
	
	//verificar se é a primeira vez
	if((sequencia = fopen("sequencia.txt","r")) == NULL) {
		//abrir o arquivo para gravação
		sequencia = fopen("sequencia.txt","w");
		fprintf(sequencia, "%i",1);
		fclose(sequencia);
		
		return 1;
	}
	//depois da primeira vez
	while((fscanf(sequencia, "%i", &numero)) != EOF) {
		numero++;
	}
	//fechar arquivo
	fclose(sequencia);
	
	//abrir o arquivo para gravação
	sequencia = fopen("sequencia.txt","w");
	fprintf(sequencia, "%i", numero);
	fclose(sequencia);
	
	return numero;
}

//cadastrar projeto function
void cad_projet() {
	system("cls");
	
	//numero de projeto
	projetos.numero = sequencia();
	n++;
	
	cadprojetos = fopen("projetos.txt","a");
	
	printf("Informe o titulo do projeto de pesquisa: ");
	fflush(stdin);
	gets(projetos.titulo);
	
	printf("Informe o nome do pesquisador responsavel: ");
	fflush(stdin);
	gets(projetos.pesquisador);
	
	printf("Informe a data de inicio: ");
	fflush(stdin);
	gets(projetos.data_inicio);
	
	printf("Informe a data de fim: ");
	fflush(stdin);
	gets(projetos.data_fim);
	
	printf("Informe o valor: ");
	scanf("%f", &projetos.valor);
	
	//gravar as informações no arquivo
	fwrite(&projetos,sizeof(projetos),1,cadprojetos);
	
	//fechar o arquivo
	fclose(cadprojetos);
}

//alterar projeto function
void change_projet() {
	system("cls");
	
	//local variables
	int dados, i=0;
	
	n = sequencia();
	//alterar dados de projeto
	printf("Informe o numero do projeto que deseja alterar: ");
	scanf("%i", &dados);
	
	
	cadprojetos = fopen("projetos.txt","r+b");
	
	fseek(cadprojetos, sizeof(projetos), SEEK_SET);
		
	while(fread(&projetos, 0*sizeof(projetos),1,cadprojetos) == 1) {
		if(projetos.numero == dados) {
			printf(":::::: DADOS ATUAIS ::::::\n");
			
			printf("Numero do projeto:..... %i\n", projetos.numero);
			printf("Titulo do projeto:..... %s\n", projetos.titulo);
			printf("Nome do pesquisador:... %s\n", projetos.pesquisador);
			printf("Data de inicio:........ %s\n", projetos.data_inicio);
			printf("Data de fim:........... %s\n", projetos.data_fim);
			printf("Valor do projeto:...... %.2f\n\n", projetos.valor);
			
			printf(":::::: DADOS NOVOS ::::::\n");
			
			printf("\nInforme o novo titulo do projeto de pesquisa: ");
			fflush(stdin);
			gets(projetos.titulo);
			
			printf("Informe o novo nome do pesquisador responsavel: ");
			fflush(stdin);
			gets(projetos.pesquisador);
			
			printf("Informe a nova data de inicio: ");
			fflush(stdin);
			gets(projetos.data_inicio);
			
			printf("Informe a nova data de fim: ");
			fflush(stdin);
			gets(projetos.data_fim);
			
			printf("Informe o novo valor: ");
			scanf("%f", &projetos.valor);
		}
	}
	
	fseek(cadprojetos, sizeof(projetos), SEEK_SET);
	
	//gravar as informações no arquivo
	fwrite(&projetos,sizeof(projetos),1,cadprojetos);
	
	//fechar o arquivo
	fclose(cadprojetos);
	
	printf("\n\nPROJETO ALTERADO...\n\n");
	
	system("pause");
}

//pesquisar projetos function
void search_projet() {
	system("cls");
	
	//local variables
	int dados, i=0;
	
	//pesquisar projeto
	printf("Informe o numero do projeto que deseja pesquisar: ");
	scanf("%i", &dados);
	
	system("cls");
	
	cadprojetos = fopen("projetos.txt","r");
	
	while(fread(&projetos, sizeof(projetos),1,cadprojetos) == 1) {
		if(projetos.numero == dados) {
			printf("Numero do projeto: %i\n", projetos.numero);
			printf("Titulo do projeto: %s\n", projetos.titulo);
			printf("Nome do pesquisador responsavel: %s\n", projetos.pesquisador);
			printf("Data de inicio: %s\n", projetos.data_inicio);
			printf("Data de fim: %s\n", projetos.data_fim);
			printf("Valor do projeto: %.2f\n\n", projetos.valor);
		}
	}
	fclose(cadprojetos);
	
	system("pause");
}

//listar projetos function
void show_projet() {
	system("cls");
	
	//abrir o arquivo para leitura
	if((cadprojetos = fopen("projetos.txt","r")) == NULL) {
		printf("\n\nErro na abertura do arquivo...\n");
		system("pause");
		exit(0);
	}
	
	while(fread(&projetos, sizeof(projetos),1,cadprojetos) == 1) {
		printf("Numero do projeto:..... %i\n", projetos.numero);
		printf("Titulo do projeto:..... %s\n", projetos.titulo);
		printf("Nome do pesquisador:... %s\n", projetos.pesquisador);
		printf("Data de inicio:........ %s\n", projetos.data_inicio);
		printf("Data de fim:........... %s\n", projetos.data_fim);
		printf("Valor do projeto:...... %.2f\n\n", projetos.valor);
	}
	fclose(cadprojetos);
	
	system("pause");
}

//menu function
void menu (int perfil) {
	system("cls");
	
	//local variables
	int opcao;
	printf("*** MENU ***");
	
	if(perfil == 1) {
		printf("\n1 - Cadastrar usuario");
	}
	printf("\n2 - Cadastrar projeto de pesquisa");
	printf("\n3 - Alterar projeto de pesquisa");
	printf("\n4 - Pesquisar projeto de pesquisa por numero");
	printf("\n5 - Listar projeto de pesquisa (ordem alfabetica)");
	printf("\n0 - Sair");
	
	printf("\n\nEscolha uma opcao: ");
	scanf("%i", &opcao);
	
	if(opcao == 1) {
		cad_usuario(1);
		menu(perfil);
	}
	switch(opcao) {
		case 2 : {
			cad_projet();
			menu(perfil);
		}
		case 3 : {
			change_projet();
			menu(perfil);
		}
		case 4 : {
			search_projet();
			menu(perfil);
		}
		case 5 : {
			show_projet();
			menu(perfil);
		}
		case 0 : {
			exit(0);
		}
		default : {
			printf("\nOpcao invalida...\n\n");
			system("pause");
			menu(perfil);
		}
	}
}

//login function
void logar() {
	system("cls");
	
	//variaveis auxiliares
	char auxlogin[15], auxsenha[10], resposta;
	int flag = 0;
	
	//abrir o arquivo para leitura ou gravação
	if((login = fopen("usuario.txt","rb")) == NULL) {
		printf("Primeiro acesso... Cadastrar usuario admin!\n\n");
		system("pause");
		cad_usuario(0);
		system("cls");
		
		printf("Deseja efetuar login? <S/N> ");
		resposta = getche();
		
		if(toupper(resposta) == 'S') {
			logar();
		}
		else {
			exit(0);
		}
	}
	else {
		printf("Informe o login: ");
		fflush(stdin);
		gets(auxlogin);
		
		printf("Informe a senha: ");
		fflush(stdin);
		gets(auxsenha);
		
		while(fread(&usuarios,sizeof(usuarios),1,login) == 1) {
			if((strcmp(usuarios.login,auxlogin) == 0) && strcmp(usuarios.senha,auxsenha) == 0) {
				menu(usuarios.perfil);
				flag = 1;
			}
		}
		if(flag == 0) {
			printf("\nUsuario nao encontrado... Tente novamente!\n\n");
			system("pause");
			logar();
		}
	}
}

//main function
main() {
	logar();
}
