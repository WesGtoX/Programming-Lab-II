//Algoritmo para validar usuário e senha

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//variables
char usuario[10], senha[20];
int flag = 0;

//main function
main () {
	while(flag == 0) {
		system("cls");
		printf("Informe o nome do usuario: ");
		fflush(stdin);
		gets(usuario);
		
		//compare two strings
		if(strcmp(usuario,"engenharia")==0) {
			printf("\nUSUARIO VALIDO....\n");
		//	system("pause");
			flag = 1;
		}
		else {
			printf("\nUSUARIO INVALIDO....\n\n");
			system("pause");
			flag = 0;
		}
	}
	
	printf("\nInforme a senha: ");
	fflush(stdin);
	gets(senha);
	if(strcmp(senha,"unaerp")==0) {
		printf("\nLogin realizado com sucesso....\n\n");
		system("pause");
	}
	else {
		printf("\nSenha invalida....\n\n");
		system("pause");
		//sai imediatamente do programa (fechar o algoritmo
		exit(0);
	}
}
