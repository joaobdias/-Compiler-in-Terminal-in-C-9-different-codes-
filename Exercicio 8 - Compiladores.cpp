#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 63

int main () {

setlocale(LC_ALL,"Portuguese");

	while (1) { //looping para programa se repetir
	
	// criação das variáveis a serem usadas
		system("cls");
		int tamstr = 0, i = 0, aux = 0, aux2 = 0, operando = 0, operador = 0,erro1 = 0,erro2 = 0,erro3 = 0;
		char texto[31],op1[20],op2[20],op3[20],operadores[2];
		bool tamexc = false;
		
		memset(op1, 0, 20);
		memset(op2, 0, 20);
		memset(op3, 0, 20);
		memset(operadores,0,2);
		memset(texto, 0, 31);
	
		printf("Digite a expressão:");
    	fflush(stdin); // limpa buffer de entrada de dados
    	gets(texto); // recebe o texto escrito e armazena em texto
    	tamstr = strlen(texto); // tamanho exato da string
    	
    
    		if (tamstr >= 32){ //se o tamanho da string exceder o limite da variavel texto
    			printf("\nERRO: Tamanho da expressão ultrapassa limite máximo de 32 caracteres\n");
    			tamexc = true; //não executa mais o programa
			}
		
			if (tamexc == false) { //se a etapa anterior for concluida com sucesso, continua
				
				for (i = 0; i <= tamstr-1; i++){ //looping para identificar sinal de atribuição, operandos e operadores
					
					if (texto[i] == ' ') { // pula os espaços em branco se achar
						while (texto[i+1] == ' ')
							i++;
					} else if ((isalpha(texto[i])) || (isdigit(texto[i]))) { // se achar uma letra ou numero
						
						aux = i;
						while (texto[i+1] == ' ') // pula os espaços em branco
							i++;
						
						if ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) //se achar outra letra ou numero, dá erro
							erro1++;
						
						else {
							
							if (operando == 0){ //if's para armazenar os operandos em stings para posterior utilização 
								op1[0] = texto[aux];
								operando++;
							} else if (operando == 1){
								op2[0] = texto[aux];
								operando++;
							} else if (operando == 2){
								op3[0] = texto[aux]; 
								operando++;
							}
							
							if (operando >= 4) // caso exceda o limite de operandos, há erro
								erro3++;
						}
						
					} else if ((texto[i] == '/') || (texto[i] == '*') || (texto[i] == '+') || (texto[i] == '-')) { // se achar algum simbolo
						
						aux = i;
						while (texto[i+1] == ' ') //pula os espaços em branco
							i++;
						
						if ((texto[i+1] == '/') || (texto[i+1] == '*') || (texto[i+1] == '+') || (texto[i+1] == '-')) // se achar outro simbolo, dá erro
							erro2++;
							
						else { //soma contador de operadores e armazena numa string para posterior utilização
							operador++;
							operadores[aux2] = texto[aux];
							aux2++;
							
							if (operador >= 3) // se houver mais operadores, dá erro
								erro3++;
							
						}
					}		 
				}
			// if's para mostrar caso tenha erros na expressão digitada com base nos valores obtidos na etapa anterior
			if ((erro3 > 0) && (erro2 == 0) && (erro1 == 0)) {
				printf("\nERRO: Há operandos e/ou operadores demais na expressão.\n");
			} else if ((erro3 == 0) && (erro2 > 0) && (erro1 == 0)){
				printf("\nERRO: Há operadores demais entre os operandos.\n");
			} else if ((erro3 == 0) && (erro2 == 0) && (erro1 > 0)){
				printf("\nERRO: Há erros de sintaxe nos operandos.\n");
			} else if ((erro3 > 0) && (erro2 > 0) && (erro1 > 0)){
				printf("\nERRO: Há muitos erros de sintaxe na expressão.\n");
			} else if ((erro3 == 0) && (erro2 == 0) && (erro1 == 0)){ // se der tudo certo, mostra as três formas na tela
				printf("\n1ª Forma pósfixa: %s %c %s %s %c",op1,operadores[0],op2,op3,operadores[1]);
				printf("\n2ª Forma pósfixa: %s %s %c %s %c",op1,op2,operadores[0],op3,operadores[1]);
				printf("\n3ª Forma pósfixa: %s %s %s %c %c\n",op1,op2,op3,operadores[0],operadores[1]);
			}
		}
			system("pause");
	}
}

		
