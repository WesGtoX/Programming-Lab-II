Ordenação

Algoritmo Bubble Sort (ordenação bolha)

 0	1	2	3	4	5	6
{3	5	10	8	12	7	1}
 ^
===================
ORDEM CRESCENTE

aux = 3
vetor[0] = 1
vetor[6] = 3

for(i=0; i < 7; i++)  {
	for(j=i+1; j < 7; j++) {
		if(vetor[i]) > vetor[3]) {
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
		}
	}
}
 0	1	2	3	4	5	6
{1	3	5	7	8	10	12}

===================
