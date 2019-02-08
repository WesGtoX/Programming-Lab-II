//Gerenciador de sequ�ncia

//libraries
#include <stdio.h>
#include <stdlib.h>

//fun��o sequ�cia
int sequencia() {
	//local variables
	int numero;
	
	//ponteiro para o arquivo
	FILE *pontseq;
	
	//verificar se �  a primeira vez
	if((pontseq = fopen("sequencia.txt","r")) == NULL) {
		//abrir o arquivo para grava��o
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
	
	//abrir o arquivo para grava��o
	pontseq = fopen("sequencia.txt","w");
	fprintf(pontseq, "%i", numero);
	fclose(pontseq);
	
	return numero;
}

main() {
	//function sequencia() call
	printf("Sequencia: %i\n\n", sequencia());
	
	system("pause");
}
