#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main() { 
	
	setlocale(LC_ALL, "Portuguese"); //setlocale para possibilitar a acentuação dos caracteres
	char str[50]; //criação das strings utilizadas
	int tamstr,i,maius,minus; // criação dos inteiros utilizados
	maius = 0; //definição dos valores base 0 para as variaveis que determinam a quantidade de maiuscula e minuscula
	minus = 0;
	
	printf("Digite o texto desejado: "); //print na tela
	gets(str); //determinação do texto que será utilizado
	tamstr = strlen(str); //tamanho exato da string que foi escrita
	
	char maiusc[tamstr], minusc[tamstr]; // criação das strings auxiliares com o tamanho da string escrita pelo usuário
	
			for (i = 0; i<= tamstr; i++) { // looping para verificação dos caracteres minusculos e maiusculos
				if (islower(str[i])) { // se for minusculo
					minus++; //incrementa no contador de minusculos
} 
				else if (isupper(str[i])) { // se for maiúsculo
					maius++; //incrementa no contador de maiúsculos
 }
}
			if ((minus > 0) && (maius > 0)) { // verificação se existem letras maiusculas e minusculas na frase		
				for (i = 0; i<= tamstr; i++) { // looping para transformar os caracteres em maiúsculo
					maiusc[i]= toupper(str[i]); // armazena os valores transformados no vetor auxiliar
}
				for (i = 0; i<= tamstr; i++) { // looping para transformar os caracteres em minusculo
					minusc[i]= tolower(str[i]); // armazena os valores transformados no vetor auxiliar
}
				printf("\nFrase Minuscula: %s\n",minusc); //print das frases já transformadas em maiuscula e minuscula
				printf("\nFrase Maiúscula: %s\n",maiusc);

			} else if ((minus > 0) && (maius == 0)) { // verificação se existem minusculas mas sem maiusculas
				for (i = 0; i<= tamstr; i++) { // looping para transformar os caracteres em maiúsculo
					maiusc[i]= toupper(str[i]); // armazena os valores transformados no vetor auxiliar
				}
				printf("\nFrase Maiúscula: %s\n",maiusc); //print da frase já transformada em maiuscula
				
			} else if ((minus == 0) && (maius > 0)) { // verificação se existem maiusculas mas sem minusculas
				for (i = 0; i<= tamstr; i++) { // looping para transformar os caracteres em minusculo
					minusc[i]= tolower(str[i]); // armazena os valores transformados no vetor auxiliar
}
				printf("\nFrase Minuscula: %s\n",minusc); //print da frase já transformada em minuscula
}
	return 0;
}
