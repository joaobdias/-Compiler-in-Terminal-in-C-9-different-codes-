#include <stdio.h>
#include <string.h>
#include <locale.h>

void main() { 
	
	setlocale(LC_ALL, ".OCP"); //setlocale para possibilitar a acentuação dos caracteres
	char str[50],str2[50]; //criação das strings utilizadas
	int qespaco,qletras,tamstr,i,aux; // criação dos inteiros utilizados
	
	printf("Digite o texto desejado: "); //print na tela da mensagem
	gets(str); //determinação do texto que será utilizado
	tamstr = strlen(str); //tamanho exato da string que foi escrita
			
	for (i = 0; i<= tamstr; i++) { // looping para verificação dos espaços em branco ou não
		if (str[i] != ' ') { // se o elemento i do vetor str (escrito pelo usuário) não for espaço em branco
			str2[aux] = str[i];  //escreve esse elemento em um vetor auxiliar
			aux++; //incremento no auxiliar de local no segundo vetor
}		
		else { // se não houver um caracter no local, é espaço em branco
			qespaco++; //incrementa o espaço em branco no contador de espaço em branco
 }
}	 

	printf("\n- Junto: %s\n",str2); //print na tela da string sem espaço em branco
	printf("- Em branco: %d\n", qespaco); //print na tela da quantidade de espaço em branco
	printf("- Numero Caracteres: %d\n", strlen(str2)); //print na tela na quantidade de caracteres
}
