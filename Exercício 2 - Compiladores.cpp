#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main() { 
	
	setlocale(LC_ALL, "Portuguese"); //setlocale para possibilitar a acentua��o dos caracteres
	char str[50]; //cria��o das strings utilizadas
	int tamstr,i,maius,minus; // cria��o dos inteiros utilizados
	maius = 0; //defini��o dos valores base 0 para as variaveis que determinam a quantidade de maiuscula e minuscula
	minus = 0;
	
	printf("Digite o texto desejado: "); //print na tela
	gets(str); //determina��o do texto que ser� utilizado
	tamstr = strlen(str); //tamanho exato da string que foi escrita
	
	char maiusc[tamstr], minusc[tamstr]; // cria��o das strings auxiliares com o tamanho da string escrita pelo usu�rio
	
			for (i = 0; i<= tamstr; i++) { // looping para verifica��o dos caracteres minusculos e maiusculos
				if (islower(str[i])) { // se for minusculo
					minus++; //incrementa no contador de minusculos
} 
				else if (isupper(str[i])) { // se for mai�sculo
					maius++; //incrementa no contador de mai�sculos
 }
}
			if ((minus > 0) && (maius > 0)) { // verifica��o se existem letras maiusculas e minusculas na frase		
				for (i = 0; i<= tamstr; i++) { // looping para transformar os caracteres em mai�sculo
					maiusc[i]= toupper(str[i]); // armazena os valores transformados no vetor auxiliar
}
				for (i = 0; i<= tamstr; i++) { // looping para transformar os caracteres em minusculo
					minusc[i]= tolower(str[i]); // armazena os valores transformados no vetor auxiliar
}
				printf("\nFrase Minuscula: %s\n",minusc); //print das frases j� transformadas em maiuscula e minuscula
				printf("\nFrase Mai�scula: %s\n",maiusc);

			} else if ((minus > 0) && (maius == 0)) { // verifica��o se existem minusculas mas sem maiusculas
				for (i = 0; i<= tamstr; i++) { // looping para transformar os caracteres em mai�sculo
					maiusc[i]= toupper(str[i]); // armazena os valores transformados no vetor auxiliar
				}
				printf("\nFrase Mai�scula: %s\n",maiusc); //print da frase j� transformada em maiuscula
				
			} else if ((minus == 0) && (maius > 0)) { // verifica��o se existem maiusculas mas sem minusculas
				for (i = 0; i<= tamstr; i++) { // looping para transformar os caracteres em minusculo
					minusc[i]= tolower(str[i]); // armazena os valores transformados no vetor auxiliar
}
				printf("\nFrase Minuscula: %s\n",minusc); //print da frase j� transformada em minuscula
}
	return 0;
}
