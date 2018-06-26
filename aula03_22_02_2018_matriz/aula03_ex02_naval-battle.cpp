/*Implementar um jogo de batalha naval considerando as premissas:
1 - haverá um tabuleiro com 100 posições (10 linhas x10 colunas);
2 - cada posição terá o valor (0 ou 1 aleatóriamente e inicializada pelo sistema);
3 - o jogador deverá informar o número de vidas que deseja e seu nome antes de iniciar o jogo;
4 - haverá um contador para somar os acertos (pontos) de jogador, quando ele acertar o valor 1 ele ganha 1 ponto;
5 - quando o jogador acertar o valor 0 ele perderá uma vida;
6 - o jogador deverá informar linha e coluna (jogada), verificar se ele ganhou ponto ou perdeu vida;
7 - quando as vidas chegarem em 0 o jogo termina;
8 - a posição escolhida pelo usuário (deve ser anulada), ou seja, não perderá vida e nem contará pontos;
9 - quando o jogo terminar, mostrar o nome do jogador e a quantidade de pontos. */

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//variables
int board[10][10], i, j, qtdlife, life;
char name[30];

//header function
void header() {
	system("cls");
	
	printf("Jogador: %s", name);
	if(life<=qtdlife) {
		printf("\t\tVidas: ");
		for(i=0;i<=qtdlife;i++) {
			printf("\xB2");
		}
		//printf("\t\tVidas: \178");
	}
	printf("\n\n");
	//printf("\t\tVidas: %i\n\n", life);
	//printf("\178");
}

void status() {
	printf("Informe o seu nome: ");
	fflush(stdin);
	gets(name);
	
	printf("Informe a quantidade de vidas: ");
	scanf("%i", &qtdlife);
	
	life = qtdlife;
	
	//%c, 178
}

//show board game
void showboard() {
	for(i=0; i<10; i++) {
		for(j=0; j<10; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}

//main function
main() {
	
	status(); //call function status
	
	srand(time(NULL));
	for(i=0; i<10; i++) {
		for(j=0; j<10; j++) {
			board[i][j] = rand()%2;
		}
	}
	
	while(life != 0) {
		
		header(); //call function header
		
		showboard(); //call function board
		
		printf("\n\nInforme a posicao X de sua jogada: ");
		scanf("%i", &j);
		
		printf("Informe a posicao Y de sua jogada: ");
		scanf("%i", &i);
		
		if(board[i][j] == 1) {
			board[i][j] = 2;
		}
		else {
			life--;
			printf("\n\nPERDEU UMA VIDA!!\n\n");
		}
		
		system("pause");
		
		system("cls");
	}
	system("pause");
}
