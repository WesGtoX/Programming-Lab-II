/*Exercicio
Elaborar um programa para cadastrar produtos, sendo que o 
código do produto deve ser gerado automaticamente (sequência).
Registra-se de cada produto, código (sequência), nome e o valor.
O programa deve permitir cadastrar e listar os produtos cadastrados.
Utilizar estrutura para o cadastrado/listagem do produto e funções*/

//libraries
#include <stdio.h>
#include <stdlib.h>

//struct
struct cadastro {
	int codigo;
	char nome[30];
	float valor;
};
struct cadastro produto;

//ponteiro para o arquivo
FILE *cadprodut;

//função sequêcia
int sequencia() {
	//local variables
	int numero;
	
	//ponteiro para o arquivo
	FILE *pontseq;
	
	//verificar se é  a primeira vez
	if((pontseq = fopen("sequencia.txt","r")) == NULL) {
		//abrir o arquivo para gravação
		pontseq = fopen("sequencia.txt","w");
		fprintf(pontseq, "%i", 1);
		fclose(pontseq);
		
		return 1;
	}
	//depois da primeira vez
	while((fscanf(pontseq, "%i", &numero)) != EOF) {
		numero++;
	}
	//fechar arquivo
	fclose(pontseq);
	
	//abrir o arquivo para gravação
	pontseq = fopen("sequencia.txt","w");
	fprintf(pontseq, "%i", numero);
	fclose(pontseq);
	
	return numero;
}

void regproduto() {
	system("cls");
	
	//codigo do produto
	produto.codigo = sequencia();
	
	cadprodut = fopen("produtos.txt","a");
	
	printf("Informe o nome do produto: ");
	fflush(stdin);
	gets(produto.nome);
	
	printf("Informe o valor do produto: ");
	scanf("%f", &produto.valor);
	
	//gravar as informações no arquivo
	fwrite(&produto, sizeof(produto), 1, cadprodut);
	
	//fechar o arquivo
	fclose(cadprodut);
}

void listar() {
	system("cls");
	
	//abrir o arquivo para leitura
	if((cadprodut = fopen("produtos.txt","r")) == NULL) {
		printf("\n\nErro na abertura do arquivo...\n");
		system("pause");
		exit(0);
	}
	
	while(fread(&produto, sizeof(produto), 1, cadprodut) == 1) {
		printf("Codigo do produto: %i", produto.codigo);
		printf("\nNome do produto: %s", produto.nome);
		printf("\nValor do produto: %.2f\n\n", produto.valor);
	}
	fclose(cadprodut);
	
	system("pause");
}

void menu() {
	system("cls");
	
	//local variables
	int opcao;
	
	printf("1 - Cadastrar Produto\n2 - Listar Produtos\n0 - Sair");
	printf("\n\nEscolha uma opcao: ");
	scanf("%i", &opcao);
	
	switch(opcao) {
		case 1 : {
			regproduto();
			menu();
			break;
		}
		case 2 : {
			listar();
			menu();
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

main() {
	menu();
}
