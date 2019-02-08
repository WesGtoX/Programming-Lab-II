/*Trabalho - até 4 pontos - entregar até 20/06/2018
Elaborar um programa que contemple:
1 - Abertura do programa com validação de usuário e senha;
2 - Cadastro; Alteração; Listagem; Consulta de livros.
3 - Armazenar dos livros: Código (Gerar Automaticamente); Título; Autores; ISBN; Editora; Ano de Publicação.
4 - As consultas podem ocorrer por: Código; Título do livro; Período de publicação (Ano Inicial - Ano Final);
5 - A listagem deve ser feita em ordem alfabética de título;
6 - Gerenciar as funções por meio de um menu;
7 - Utilizar funções;
8 - Armazenar o registro dos livros em modo binário;*/

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

//struct
typedef struct usuario {
	char nome[30];
	char login[15];
	char senha[10];
} usuario;

usuario usuarios;

typedef struct book {
	int codigo;
	char titulo[50];
	char autores[50];
	char isbn[14];
	char editora[50];
	int ano;
} book;

book books;

//prototype functions
void menu();
void show();

//files
FILE *login;
FILE *cadbooks;

//function cadastro de usuário
void cad_usuario() {
	system("cls");
	
	//open file for recording in binary mode
	login = fopen("usuario.txt","ab");
	
	printf("Nome: ");
	fflush(stdin);
	gets(usuarios.nome);
	
	printf("Login: ");
	fflush(stdin);
	gets(usuarios.login);
	
	printf("Senha: ");
	fflush(stdin);
	gets(usuarios.senha);
	
	//save to file
	fwrite(&usuarios, sizeof(usuarios),1,login);
	
	//close file
	fclose(login);
}

//function sequence
int sequencia() {
	//local variables
	int numero;
	
	//file pointer
	FILE *sequencia;
	
	//check if it's the first time
	if((sequencia = fopen("sequencia.txt","r")) == NULL) {
		//open file for recording
		sequencia = fopen("sequencia.txt","w");
		fprintf(sequencia, "%i",1);
		fclose(sequencia);
		
		return 1;
	}
	//after the first time
	while((fscanf(sequencia, "%i", &numero)) != EOF) {
		numero++;
	}
	//close file
	fclose(sequencia);
	
	//open file for recording
	sequencia = fopen("sequencia.txt","w");
	fprintf(sequencia, "%i", numero);
	fclose(sequencia);
	
	return numero;
}

//function 
void cad_book() {
	//local variables
	char control;
	
	do {
		system("cls");
		
		//open file for recording in binary mode
		cadbooks = fopen("books.txt","ab");
	
		//books code
		books.codigo = sequencia();
		
		printf("Título......: ");
		fflush(stdin);
		gets(books.titulo);
		
		printf("Autor(es)...: ");
		fflush(stdin);
		gets(books.autores);
		
		printf("ISBN........: ");
		fflush(stdin);
		gets(books.isbn);
		
		printf("Editora.....: ");
		fflush(stdin);
		gets(books.editora);
		
		printf("Ano.........: ");
		scanf("%i", &books.ano);
		
		//save the information in the file
		fwrite(&books,sizeof(books),1,cadbooks);
		
		//close file
		fclose(cadbooks);
		
		printf("\nCadastrar outro livro? <S/N>: ");
		control = getche();
		
	} while(toupper(control) == 'S');
}

//function change book data
void change_book() {
	//local variables
	int dados, i=0;
	char controlA, controlB;
	
	do {
		do {
			system("cls");
			
			//open file for reading
			if((cadbooks = fopen("books.txt","r")) == NULL) {
				printf("\nNenhum livro cadastrado...\n\n");
				system("pause");
				//call function menu()
				menu();
			}
			//change book data
			printf("Informe o código do livro que deseja alterar: ");
			scanf("%i", &dados);
			
			system("cls");

			while(fread(&books,sizeof(books),1,cadbooks) == 1) {
				if(books.codigo == dados) {
					i = 1;
					printf("--------------");
					printf("\nDADOS ANTIGOS:");
					printf("\n--------------\n\n");
					
					//call function show()	
					show();
				}
			}
			
			//close file
			fclose(cadbooks);
			
			printf("Este é realmente o livro que deseja lterar? <S/N>: ");
			controlA = getche();
			
		} while(toupper(controlA) == 'N');
		
		if(i == 0) {
			printf("\nLivro não encontrado...\n\n");
			system("pause");
			
			change_book();
		}
		else {
			printf("\n\nINFORME OS NOVOS DADOS:");
			printf("\n-----------------------\n");
			
			cadbooks = fopen("books.txt", "r+w");
			
			fseek(cadbooks,(dados-1)*sizeof(books),SEEK_SET);
			
			books.codigo = dados;
			
			printf("\nTítulo......: ");
			fflush(stdin);
			gets(books.titulo);
			
			printf("Autor(es)...: ");
			fflush(stdin);
			gets(books.autores);
			
			printf("ISBN........: ");
			fflush(stdin);
			gets(books.isbn);
			
			printf("Editora.....: ");
			fflush(stdin);
			gets(books.editora);
			
			printf("Ano.........: ");
			scanf("%i", &books.ano);
			
			//save the information in the file
			fwrite(&books,sizeof(books),1,cadbooks);
		
			//close file
			fclose(cadbooks);
			
			printf("\n\nLIVRO ALTERADO...");
			printf("\n-----------------\n");
		}
		
		printf("\nAlterar outro livro? <S/N>: ");
		controlB = getche();
		
	} while(toupper(controlB) == 'S');
}

//function show books
void show_book() {
	system("cls");
	
	//open file for reading
	if((cadbooks = fopen("books.txt","r")) == NULL) {
		printf("\nNenhum livro cadastrado...\n\n");
		system("pause");
		//call function menu()
		menu();
	}
	
	while(fread(&books,sizeof(books),1,cadbooks) == 1) {
		//call function show()
		show();
	}
	//close file
	fclose(cadbooks);
	
	system("pause");
}

//function show books in order
void show_inorder() {
	system("cls");

	//local variables
	int counter;
	int i=0, j, auxcod, auxano;
	char auxtittle[50], auxauthors[50], auxisbn[14], auxeditora[50];

	//file pointer
	FILE *sequencia;
	
	//open file for reading
	if((sequencia = fopen("sequencia.txt","r")) == NULL) {
		printf("\nNenhum livro cadastrado...\n\n");
		system("pause");
		//call function menu()
		menu();
	}
	//counter for show books in order
	sequencia = fopen("sequencia.txt","r");
	while ((fscanf(sequencia, "%d", &counter)) != EOF);
	fclose(sequencia);
	
	//struct to do sorting
	typedef struct bookorder {
		int codigo_order;
		char titulo_order[50];
		char autores_order[50];
		char isbn_order[14];
		char editora_order[50];
		int ano_order;
	} bookorder;
	
	bookorder booksorder[counter];
	
	//open file for reading
	if((cadbooks = fopen("books.txt","r")) == NULL) {
		printf("\nNenhum livro cadastrado...\n\n");
		system("pause");
		//call function menu()
		menu();
	}	
	while(fread(&books,sizeof(books),1,cadbooks) == 1) {
		booksorder[i].codigo_order = books.codigo;
		strcpy(booksorder[i].titulo_order,books.titulo);
		strcpy(booksorder[i].autores_order,books.autores);
		strcpy(booksorder[i].isbn_order,books.isbn);
		strcpy(booksorder[i].editora_order,books.editora);
		booksorder[i].ano_order = books.ano;
		
		i++;
	}
	//ordering
	for(i=0; i < counter; i++) {
		for(j=i+1; j < counter; j++) {
			if(toupper(strcmp(booksorder[i].titulo_order,booksorder[j].titulo_order) > 0)) {
				auxcod 	= booksorder[i].codigo_order;
				strcpy(auxtittle,booksorder[i].titulo_order);
				strcpy(auxauthors,booksorder[i].autores_order);
				strcpy(auxisbn,booksorder[i].isbn_order);
				strcpy(auxeditora,booksorder[i].editora_order);
				auxano = booksorder[i].ano_order;
				
				booksorder[i].codigo_order = booksorder[j].codigo_order;
				strcpy(booksorder[i].titulo_order,booksorder[j].titulo_order);
				strcpy(booksorder[i].autores_order,booksorder[j].autores_order);
				strcpy(booksorder[i].isbn_order,booksorder[j].isbn_order);
				strcpy(booksorder[i].editora_order,booksorder[j].editora_order);
				booksorder[i].ano_order = booksorder[j].ano_order;
				
				booksorder[j].codigo_order = auxcod;
				strcpy(booksorder[j].titulo_order,auxtittle);
				strcpy(booksorder[j].autores_order,auxauthors);
				strcpy(booksorder[j].isbn_order,auxisbn);
				strcpy(booksorder[j].editora_order,auxeditora);
				booksorder[j].ano_order = auxano;
			}
		}
	}
	for(i=0; i < counter; i++) {
		printf("Código.....: %i\n", booksorder[i].codigo_order);
		printf("Título.....: %s\n", booksorder[i].titulo_order);
		printf("Autor(s)...: %s\n", booksorder[i].autores_order);
		printf("ISBN.......: %s\n", booksorder[i].isbn_order);
		printf("Editora....: %s\n", booksorder[i].editora_order);
		printf("Ano........: %i\n", booksorder[i].ano_order);
		printf("------------------------------\n\n");
	}
	//close file
	fclose(cadbooks);
	
	system("pause");
}

//function show
void show() {
	printf("Código.....: %i\n", books.codigo);
	printf("Título.....: %s\n", books.titulo);
	printf("Autor(s)...: %s\n", books.autores);
	printf("ISBN.......: %s\n", books.isbn);
	printf("Editora....: %s\n", books.editora);
	printf("Ano........: %i\n", books.ano);
	printf("------------------------------\n\n");
}

//function procurar livro
void search_book() {
	system("cls");
	
	//open file for reading
	if((cadbooks = fopen("books.txt","r")) == NULL) {
		printf("\nNenhum livro cadastrado...\n\n");
		system("pause");
		//call function menu()
		menu();
	}
	
	//local variables
	int dados, opcao, cod=0, year, yearp, yearf, period, ppublica;
	char tittle[50];
	
	printf("=====================================\n");
	printf("======== CONSULTA DE LIVROS =========\n");
	printf("=====================================\n");
	printf("\n1 - Consultar por Código do Livro");
	printf("\n2 - Consultar por Título do Livro");
	printf("\n3 - Consultar por Período de Publicação");
	printf("\n0 - Voltar para o Menu");
	
	printf("\n\nEscolha uma opção: ");
	scanf("%i", &opcao);
	
	switch(opcao) {
		case 1 : {
			system("cls");
			
			//local variables			
			int i=0;
			
			//search project
			printf("Informe o código do livro que deseja consultar: ");
			scanf("%i", &cod);
			
			system("cls");
			
			cadbooks = fopen("books.txt","r");
			
			while(fread(&books,sizeof(books),1,cadbooks) == 1) {
				if(books.codigo == cod) {
					i = 1;
					//call function show()
					show();
				}
			}
			if(i == 0) {
				printf("\nLivro não encontrado...\n\n");
				system("pause");
				//call function search_book()
				search_book();
			}
			system("pause");
			
			//close file
			fclose(cadbooks);
			//call function search_book()
			search_book();
		}
		case 2 : {
			system("cls");
			
			//local variables			
			int i=0;
			
			//search project*
			printf("Informe o título do livro que deseja consultar: ");
			fflush(stdin);
			gets(tittle);
			
			system("cls");
			
			cadbooks = fopen("books.txt","r");
			
			while(fread(&books,sizeof(books),1,cadbooks) == 1) {
				if(strcmp(tittle,books.titulo) == 0) {
					i = 1;
					//call function show()
					show();
				}
			}
			if(i == 0) {
				printf("\nLivro não encontrado...\n\n");
				system("pause");
				//call function search_book()
				search_book();
			}
			system("pause");
			
			//close file
			fclose(cadbooks);
			//call function search_book()
			search_book();
		}
		case 3 : {
			system("cls");
			
			//local variables			
			int i=0;
			
			//search project
			printf("Informe o período que deseja consultar:\n\n");
			printf("De: ");
			scanf("%i", &yearp);
			
			printf("Até: ");
			scanf("%i", &yearf);
			
			system("cls");
					
			period = yearf - yearp;
			
			cadbooks = fopen("books.txt","r");
			
			while(fread(&books,sizeof(books),1,cadbooks) == 1) {
				ppublica = yearf - books.ano;
				
				if(ppublica <= period && ppublica >= 0) {
					i = 1;
					//call function show()
					show();
				}
			}
			if(i == 0) {
				printf("\nLivro não encontrado...\n\n");
				system("pause");
				//call function search_book()
				search_book();
			}
			system("pause");
			
			//close file
			fclose(cadbooks);
			//call function search_book()
			search_book();
		}
		case 0 : {
			menu();
		}
		default : {
			printf("\nOpção inválida...\n\n");
			system("pause");
			//call function search_book()
			search_book();
		}
	}
}

//function menu
void menu() {
	system("cls");
	
	//local variables
	int opcao;
	
	printf("=====================================\n");
	printf("========== BOOK MANAGEMENT ==========\n");
	printf("=====================================\n");
	printf("\n1 - Cadastrar Livro");
	printf("\n2 - Alterar Dados de Livro");
	printf("\n3 - Listar Livros");
	printf("\n4 - Listar Livros (Ordem Alfabética)");
	printf("\n5 - Consultar Livros");
	printf("\n0 - Sair");
	
	printf("\n\nEscolha uma opção: ");
	scanf("%i", &opcao);
	
	switch(opcao) {
		case 1 : {
			cad_book();
			menu();
		}
		case 2 : {
			change_book();
			menu();
		}
		case 3 : {
			show_book();
			menu();
		}
		case 4 : {
			show_inorder();
			menu();
		}
		case 5 : {
			search_book();
			menu();
		}
		case 0 : {
			system("cls");
			printf("\tSAINDO...\n");
			exit(0);
		}
		default : {
			printf("\nOpção inválida...\n\n");
			system("pause");
			menu();
		}
	}
}

//function login
void logar() {
	system("cls");
	
	//variables aux
	char auxlogin[15], auxsenha[10], resposta;
	int flag = 0;
	
	//open file for reading or writing
	if((login = fopen("usuario.txt", "rb")) == NULL) {
		printf("Primeiro acesso... Cadastrar usuário admin!\n\n");
		system("pause");
		
		cad_usuario();
		system("cls");
		
		printf("Deseja efetuar login? <S|N> ");
		resposta = getche();
		
		if(toupper(resposta) == 'S') {
			logar();
		}
		else {
			exit(0);
		}
	}
	else {
		printf("=====================================\n");
		printf("=========== EFETUAR LOGIN ===========\n");
		printf("=====================================\n\n");
		
		printf("Login: ");
		fflush(stdin);
		gets(auxlogin);
		
		printf("Senha: ");
		fflush(stdin);
		gets(auxsenha);
		
		while(fread(&usuarios,sizeof(usuarios),1,login) == 1) {
			if((strcmp(usuarios.login,auxlogin) == 0) && strcmp(usuarios.senha,auxsenha) == 0) {
				menu();
				flag = 1;
			}
		}
		if(flag == 0) {
			printf("\nUsuário não encontrado... Tente novamente!\n\n");
			system("pause");
			logar();
		}
	}
}

//function main
main() {
	setlocale(LC_ALL, "Portuguese");
	
	logar();
}
