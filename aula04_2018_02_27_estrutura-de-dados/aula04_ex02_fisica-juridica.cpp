/*Programa para receber as informações de clientes que podem ser
classificados em pessoa física ou jurídica. De qualquer cliente
armazena-se nome e telefone, quando for pessoa física registra-se
também o RG e o CPF e se pessoa jurídica registra-se o CNPJ e a IE */

//libraries
#include <stdlib.h>
#include <stdio.h>

//type of struct
struct cliente {
	char nome[30];
	char telefone[15];
};

struct fisica {
	struct cliente cliente;
	char rg[11];
	char cpf[14];
};

struct juridica {
	struct cliente cliente;
	char cnpj[18];
	char ie[18];
};

//variables
int tipo;
struct juridica clijuridica;
struct fisica clifisica;

//main function
main() {
	printf("Informe o tipo de cliente: \n1 - Fisica\n2 - Juridica\n\n");
	printf("Tipo: ");
	scanf("%i", &tipo);
	
	if(tipo == 1) {
		printf("\nInforme o nome do cliente: ");
		fflush(stdin);
		gets(clifisica.cliente.nome);
		printf("Informe o telefone do cliente: ");
		fflush(stdin);
		gets(clifisica.cliente.telefone);
		printf("Informe o RG do cliente: ");
		fflush(stdin);
		gets(clifisica.rg);
		printf("Informe o CPF do cliente: ");
		fflush(stdin);
		gets(clifisica.cpf);
	}
	
	else if(tipo == 2) {
		printf("\nInforme o nome do cliente: ");
		fflush(stdin);
		gets(clijuridica.cliente.nome);
		printf("Informe o telefone do cliente: ");
		fflush(stdin);
		gets(clijuridica.cliente.telefone);
		printf("Informe o CNPJ do cliente: ");
		fflush(stdin);
		gets(clijuridica.cnpj);
		printf("Informe o IE do cliente: ");
		fflush(stdin);
		gets(clijuridica.ie);
	}
	else
		printf("\nNao foi possivel o cadastro...");
	
}
