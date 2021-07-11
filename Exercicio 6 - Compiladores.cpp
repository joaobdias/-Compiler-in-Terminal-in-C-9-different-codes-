#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main () {

setlocale(LC_ALL,"Portuguese"); 

	while (1) { //looping para programa se repetir
	
	//criação das variaveis utilizadas no programa e limpar tela 	
	system("cls");
	char texto[31];
	int tamstr, i, aux, operando = 0, operador = 0, errop1 = 0, errop2 = 0, atribu = 0;
	bool tamexc = false, inicio = true;
		
	//determinação da expressão que será analisada	
	printf("Digite a expressão:");
    fflush(stdin); // limpa buffer de entrada de dados
    gets(texto); // recebe o texto escrito e armazena em texto
    tamstr = strlen(texto); // tamanho exato da string
    
    	if (tamstr >= 32){ //se o tamanho da string exceder o limite da variavel texto
    		printf("\nERRO: Tamanho da expressão ultrapassa limite máximo de 32 caracteres\n");
    		tamexc = true;
    		system("pause");
		}
		
		// se não ultrapassou o limite, continua
		if (tamexc == false) {	
		for (i = 0; i <= tamstr-1; i++){ //looping para identificar sinal de atribuição, operandos e operadores
			if (texto[i] == '=') // atribuição
				atribu++;
				
			else if (((isalpha(texto[i])) || (isdigit(texto[i]))) && (atribu == 0)){ //operandos
				
				while ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) // caso operando seja de vários caracteres
					i++;
				operando++;
			}
			else if ((texto[i] != ' ') && (atribu == 0)) //caso seja operadores 
				operador++;
		}
		
		if ((operador > 0) || (operando > 1) || (atribu != 1)){ // se antes da atribuição há mais operandos que o possível
		// e haja operadores ou operador de atribuição a mais, é uma expressão invalida
			printf("\nERRO: Não é uma expressão válida\n");
			system("PAUSE");
			inicio = false;
		} else { // se estiver tudo certo, zera variaveis para utilizar posteriormente
			operador = 0;
			operando = 0;
		}
	}
		
		
		if ((tamexc == false) && (inicio == true)){ // se o tamanho da expressão ou quantidade de operadores não exceder, continua
			
			for (i = 0; i <= tamstr-1; i++) { //looping para identificação de operadores, operandos e erros
							
					if (texto[i] == ' ') { // ignora espaços em branco
					while(texto[i+1] == ' ')
						i++;
					}
			
					else if ((texto[i] == '*') || (texto[i] == '/') || (texto[i] == '+') || (texto[i] == '-')) { //identificar número de operadores
						
						if ((texto[i+1] == ' ')) { //ignora espaços em branco
							while(texto[i+1] == ' ')
								i++;
						} 
						
						if ((texto[i+1] == '*') || (texto[i+1] == '/') || (texto[i+1] == '+') || (texto[i+1] == '-')) { // se achar outro operador após encontra o primeiro, é um erro
							errop1++;
							
						} else { // se não, continua
						operador++;
						
						}
					}

					else if	((isalpha(texto[i])) || (isdigit(texto[i]))) { // identificar operandos 
						
						if ((texto[i+1] == ' ')) { // ignora espaços em branco
							while(texto[i+1] == ' ')
								i++;
								
							if ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) { //se houver um carater separado por espaço em branco, é um erro
								errop2++;
								
							} else { // se não, continua
								operando++;
							} 
							
						} else {
							
							while ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) // se houver operando de vários caracteres, pula os caracter
								i++;
								
							if (texto [i+1] == ' ') { // ignora os espaços em branco
								
								while(texto[i+1] == ' ')
									i++;
								
								if ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) { // se achar outro caracter após o anterior, é um erro
								errop2++;
								
								}else { // se não, continua
								operando++;
								} 
								
							} else { // se não, continua
							operando++;
							}
						}	
					}	
			}
			
			// mostrar os resultados finais da análise da expressão 
			if ((errop1 != 0) && (errop2 == 0)){
				printf("\nERRO: Há operadores demais entre os operandos\n");
				system("PAUSE");
			} else if ((errop2 != 0) && (errop1 == 0)){
				printf("\nERRO: Há operandos separados por espaço em branco\n");
				system("PAUSE");
			} else if ((errop2 != 0) && (errop1 != 0)){
				printf("\nERRO: Há um problema com operandos e operadores");
				printf("\nOperadores demais entre os operandos e");
				printf(" operandos separados por espaço em branco\n");
				system("PAUSE");
			} else if ((errop1 == 0) && (errop2 == 0)){
				
				if ((operador > 2) && (operando < 5)){
					printf("\nERRO: Há operadores demais\n");
					system("PAUSE");
				} else if ((operador < 3) && (operando > 4)){
					printf("\nERRO: Há operandos demais\n");
					system("PAUSE");
				} else if ((operador > 2) && (operando > 4)){
					printf("\nERRO: Há operadores e operandos demais\n");
					system("PAUSE");
				} else if (operando > 1){
					printf("\nNão há problemas na expressão\n");
					
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
								while ((isalpha(texto[i+1])) || (isdigit(texto[i+1])))
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
								while ((isdigit(texto[i+1])) || (isalpha(texto[i+1]))) //percorre esse número até acabar as casas decimais
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
	}
} 
					system("PAUSE");	
				} else {
					printf("\nERRO: Não é uma expressão válida\n");
					system("PAUSE");
				}
			}
		}		
	} 			 

