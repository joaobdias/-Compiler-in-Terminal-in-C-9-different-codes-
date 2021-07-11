#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

int main () {

setlocale(LC_ALL,"Portuguese"); //set locale que permite que o printf mostre acentua��o

while (1) {
	system("cls");
	char texto[31];
	int tamstr, i=0, operando=0, opera=0, aux=0;
	
	printf("Digite a express�o:");
    fflush(stdin); //limpa o buffer de escrita do teclado STANDARD INPUT
    gets(texto); //vetor texto recebe string escrita pelo usu�rio	
    tamstr = strlen(texto);

	for (i = 0; i < tamstr; i++) { //looping para defjnir a quantidade de operadores e operandos
		
		if ((texto[i] == '*') || (texto[i] == '/') || (texto[i] == '+') || (texto[i] == '-')) // caso operador sejam os operadores aritmeticos
			opera++; // contador de operadores
		else if (isalpha(texto[i])) // caso operando seja uma variavel
			operando++; //contador de operandos
		else if (isdigit(texto[i])) { // caso operando sejam n�meros
				if (!isdigit(texto[i+1])) // caso sejam uma casa decimal
				operando++; // contador de operandos
				
				else { // caso sejam n�meros com mais de uma casa decimal
				while (isdigit(texto[i+1])) 
					i++;
				operando++; //contador de operandos
		}
	}
}

if ((opera <= 2)||(operando == 4)){ 
	for (i = 0; i < tamstr; i++) {  // looping para mostrar o que cada caractere significa na tabela de s�mbolos
					
			if (texto[i] == '*') { // caso seja operador de multiplica��o
						printf("\n %c -> Operador de Multiplica��o",texto[i]);
}
			else if (texto[i] == '/') { // caso seja operador de divis�o
						printf("\n %c -> Operador de Divis�o",texto[i]);
}
			else if (texto[i] == '+') { // caso seja operador de soma
						printf("\n %c -> Operador de Soma",texto[i]);
}
			else if (texto[i] == '-') { // caso seja operador de subtra��o
						printf("\n %c -> Operador de Subtra��o",texto[i]);
}
			else if(isalpha(texto[i])) { // caso seja uma vari�vel
				if(!isalpha(texto[i+1]))
				printf("\n %c -> Identificador",texto[i]);
				
				else {
					aux = i;
					while (isalpha(texto[i+1]))
						i++;
						
					printf("\n");
					for (aux; aux <= i; aux++) //mostra os elementos do vetor como se fosse um n�mero s�
					printf("%c",texto[aux]);
					printf(" -> Identificador",texto[i]);
	}
}
			else if (isdigit(texto[i])) { // caso seja n�mero
				if (!isdigit(texto[i+1])) // se o n�mero for de 1 casa decimal
				printf("\n %c -> N�mero",texto[i]);
				
				else { // se for mais deu ma casa decimal
				aux = i;
				while (isdigit(texto[i+1])) //percorre esse n�mero at� acabar as casas decimais
					i++;

				printf("\n");
				for (aux; aux <= i; aux++) //mostra os elementos do vetor como se fosse um n�mero s�
					printf("%c",texto[aux]);
					printf(" -> N�mero",texto[i]);
	}
}
			else if (texto[i] == '=') // caso seja o operador de atrbui��o
				printf("\n %c -> Operador de atribui��o",texto[i]);
						
			else if (texto[i] == ';') // caso seja o delimitador da equa��o
				printf("\n %c -> Delimitador",texto[i]);
				
			else if ((texto[i] != ' ')) // caso n�o sejam espa�os em branco (ele n�o conta)
				printf("\n %c n�o � um caracter v�lido pelo programa",texto[i]);			
	}
} 
			else { // caso tenha mais operadores e operandos que o poss�vel
			printf("A express�o passou do limite de operandos e operadores");  
}
		printf("\n");
		system("pause");
}
	return 0;
}
