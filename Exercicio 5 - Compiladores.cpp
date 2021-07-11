#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

int main () {

setlocale(LC_ALL,"Portuguese"); //set locale que permite que o printf mostre acentuação

while (1) {
	system("cls");
	char texto[31];
	int tamstr, i=0, operando=0, opera=0, aux=0;
	
	printf("Digite a expressão:");
    fflush(stdin); //limpa o buffer de escrita do teclado STANDARD INPUT
    gets(texto); //vetor texto recebe string escrita pelo usuário	
    tamstr = strlen(texto);

	for (i = 0; i < tamstr; i++) { //looping para defjnir a quantidade de operadores e operandos
		
		if ((texto[i] == '*') || (texto[i] == '/') || (texto[i] == '+') || (texto[i] == '-')) // caso operador sejam os operadores aritmeticos
			opera++; // contador de operadores
		else if (isalpha(texto[i])) // caso operando seja uma variavel
			operando++; //contador de operandos
		else if (isdigit(texto[i])) { // caso operando sejam números
				if (!isdigit(texto[i+1])) // caso sejam uma casa decimal
				operando++; // contador de operandos
				
				else { // caso sejam números com mais de uma casa decimal
				while (isdigit(texto[i+1])) 
					i++;
				operando++; //contador de operandos
		}
	}
}

if ((opera <= 2)||(operando == 4)){ 
	for (i = 0; i < tamstr; i++) {  // looping para mostrar o que cada caractere significa na tabela de símbolos
					
			if (texto[i] == '*') { // caso seja operador de multiplicação
						printf("\n %c -> Operador de Multiplicação",texto[i]);
}
			else if (texto[i] == '/') { // caso seja operador de divisão
						printf("\n %c -> Operador de Divisão",texto[i]);
}
			else if (texto[i] == '+') { // caso seja operador de soma
						printf("\n %c -> Operador de Soma",texto[i]);
}
			else if (texto[i] == '-') { // caso seja operador de subtração
						printf("\n %c -> Operador de Subtração",texto[i]);
}
			else if(isalpha(texto[i])) { // caso seja uma variável
				if(!isalpha(texto[i+1]))
				printf("\n %c -> Identificador",texto[i]);
				
				else {
					aux = i;
					while (isalpha(texto[i+1]))
						i++;
						
					printf("\n");
					for (aux; aux <= i; aux++) //mostra os elementos do vetor como se fosse um número só
					printf("%c",texto[aux]);
					printf(" -> Identificador",texto[i]);
	}
}
			else if (isdigit(texto[i])) { // caso seja número
				if (!isdigit(texto[i+1])) // se o número for de 1 casa decimal
				printf("\n %c -> Número",texto[i]);
				
				else { // se for mais deu ma casa decimal
				aux = i;
				while (isdigit(texto[i+1])) //percorre esse número até acabar as casas decimais
					i++;

				printf("\n");
				for (aux; aux <= i; aux++) //mostra os elementos do vetor como se fosse um número só
					printf("%c",texto[aux]);
					printf(" -> Número",texto[i]);
	}
}
			else if (texto[i] == '=') // caso seja o operador de atrbuição
				printf("\n %c -> Operador de atribuição",texto[i]);
						
			else if (texto[i] == ';') // caso seja o delimitador da equação
				printf("\n %c -> Delimitador",texto[i]);
				
			else if ((texto[i] != ' ')) // caso não sejam espaços em branco (ele não conta)
				printf("\n %c não é um caracter válido pelo programa",texto[i]);			
	}
} 
			else { // caso tenha mais operadores e operandos que o possível
			printf("A expressão passou do limite de operandos e operadores");  
}
		printf("\n");
		system("pause");
}
	return 0;
}
