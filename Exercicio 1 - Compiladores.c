#include <stdio.h>
#include <string.h>
#include <locale.h>

void main() { 
	
	setlocale(LC_ALL, ".OCP"); //setlocale para possibilitar a acentua��o dos caracteres
	char str[50],str2[50]; //cria��o das strings utilizadas
	int qespaco,qletras,tamstr,i,aux; // cria��o dos inteiros utilizados
	
	printf("Digite o texto desejado: "); //print na tela da mensagem
	gets(str); //determina��o do texto que ser� utilizado
	tamstr = strlen(str); //tamanho exato da string que foi escrita
			
	for (i = 0; i<= tamstr; i++) { // looping para verifica��o dos espa�os em branco ou n�o
		if (str[i] != ' ') { // se o elemento i do vetor str (escrito pelo usu�rio) n�o for espa�o em branco
			str2[aux] = str[i];  //escreve esse elemento em um vetor auxiliar
			aux++; //incremento no auxiliar de local no segundo vetor
}		
		else { // se n�o houver um caracter no local, � espa�o em branco
			qespaco++; //incrementa o espa�o em branco no contador de espa�o em branco
 }
}	 

	printf("\n- Junto: %s\n",str2); //print na tela da string sem espa�o em branco
	printf("- Em branco: %d\n", qespaco); //print na tela da quantidade de espa�o em branco
	printf("- Numero Caracteres: %d\n", strlen(str2)); //print na tela na quantidade de caracteres
}
