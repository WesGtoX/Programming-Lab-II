
Armazenamento de arquivo

Modos de abertura de arquivo
w - abre um arquivo texto para escrita/grava��o,
	contudo, ele sempre cria um novo arquivo.

a - abre um arquivo texto para escrita/grava��o
	e mant�m as informa��es j� existente, escrevendo
	a partir do final do arquivo.

r - abre um arquivo texto para leitura.

wb - abre um arquibo binario para escrita/grava��o,
	contudo, ele sempre criar um novo arquivo.

ab - cria um aquivo bin�rio para escrita/grava��o
	e mant�m as informa��es j� existente, escrevendo
	a partir do final do arquivo.

rb - abre um arquivo bin�rio para leitura.

fopen() - fun��o que permite a abertura de um arquivo.

Sintaxe:

fopen(nome_arquivo, modo_abertura);

Exemplo:
//abertura de um arquivo texto para grava��o
fopen("arquivo.txt","w");

//abertura de um arquivo bin�rio para grava��o
fopen("binario.txt","rb");

fclose() - fun��o que permite o fechamento de um aqrquivo

Sintaxe:
fclose(ponteiro_arquivo);

grava��o/leitura em arquivo caractere por caractere
putc() - grava em arquivo caractere por caractere
getc() - l� arquivo caractere por caractere

Sintaxe: "putc()"
putc(vari�vel,ponteiro_arquivo);

Sintaxe: "getc()"
getc(ponteiro_arquivo);

EOF (EndOfFile) - fim de arquivo.

*/
