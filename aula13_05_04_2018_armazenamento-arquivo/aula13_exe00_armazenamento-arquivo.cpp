
Armazenamento de arquivo

Modos de abertura de arquivo
w - abre um arquivo texto para escrita/gravação,
	contudo, ele sempre cria um novo arquivo.

a - abre um arquivo texto para escrita/gravação
	e mantém as informações já existente, escrevendo
	a partir do final do arquivo.

r - abre um arquivo texto para leitura.

wb - abre um arquibo binario para escrita/gravação,
	contudo, ele sempre criar um novo arquivo.

ab - cria um aquivo binário para escrita/gravação
	e mantém as informações já existente, escrevendo
	a partir do final do arquivo.

rb - abre um arquivo binário para leitura.

fopen() - função que permite a abertura de um arquivo.

Sintaxe:

fopen(nome_arquivo, modo_abertura);

Exemplo:
//abertura de um arquivo texto para gravação
fopen("arquivo.txt","w");

//abertura de um arquivo binário para gravação
fopen("binario.txt","rb");

fclose() - função que permite o fechamento de um aqrquivo

Sintaxe:
fclose(ponteiro_arquivo);

gravação/leitura em arquivo caractere por caractere
putc() - grava em arquivo caractere por caractere
getc() - lê arquivo caractere por caractere

Sintaxe: "putc()"
putc(variável,ponteiro_arquivo);

Sintaxe: "getc()"
getc(ponteiro_arquivo);

EOF (EndOfFile) - fim de arquivo.

*/
