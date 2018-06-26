//Gerenciador de sequência

//libraries
#include <stdio.h>
#include <stdlib.h>

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

main() {
	//function sequencia() call
	printf("Sequencia: %i\n\n", sequencia());
	
	system("pause");
}
