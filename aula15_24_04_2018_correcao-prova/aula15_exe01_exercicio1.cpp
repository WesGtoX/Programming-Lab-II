//Exercício 1

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

//struct
typedef struct alunos {
	int codigo;
	char nome[30];
	float parcial, final;
} alunos;

//struct declare
alunos classe[30];

//variables
int i=0;

//function register
void cadastro(alunos sala[]) {
	//local variable
	char resp='S';
	
	//repeat struct for register students
	while(toupper(resp) == 'S' && i < 30) {
		system("cls");
		printf("Informe o codigo do aluno: ");
		scanf("%i", &sala[i].codigo);
		printf("Informe o nome do aluno: ");
		fflush(stdin);
		gets(sala[i].nome);
		printf("Informe a nota parcial: ");
		scanf("%f", &sala[i].parcial);
		printf("Informe a nota final: ");
		scanf("%f", &sala[i].final);
		i++;
		printf("\nOutro aluno <S/N>: ");
		resp = getche();
	}
}

void media(alunos sala[]) {
	//local variable
	int k;
	for(k=0; k < i; k++) {
		printf("\nNome: %s", sala[k].nome);
		printf("\nMedia: %.2f\n", sala[k].parcial * 0.4 + sala[k].final * 0.6);
	}
	system("pause");
}

//main function
main() {
	//function call
	cadastro(classe);
	
	//function media
	media(classe);
}
