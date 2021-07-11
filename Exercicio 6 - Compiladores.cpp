#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main () {

setlocale(LC_ALL,"Portuguese"); 

	while (1) { //looping para programa se repetir
	
	//cria��o das variaveis utilizadas no programa e limpar tela 	
	system("cls");
	char texto[31];
	int tamstr, i, aux, operando = 0, operador = 0, errop1 = 0, errop2 = 0, atribu = 0;
	bool tamexc = false, inicio = true;
		
	//determina��o da express�o que ser� analisada	
	printf("Digite a express�o:");
    fflush(stdin); // limpa buffer de entrada de dados
    gets(texto); // recebe o texto escrito e armazena em texto
    tamstr = strlen(texto); // tamanho exato da string
    
    	if (tamstr >= 32){ //se o tamanho da string exceder o limite da variavel texto
    		printf("\nERRO: Tamanho da express�o ultrapassa limite m�ximo de 32 caracteres\n");
    		tamexc = true;
    		system("pause");
		}
		
		// se n�o ultrapassou o limite, continua
		if (tamexc == false) {	
		for (i = 0; i <= tamstr-1; i++){ //looping para identificar sinal de atribui��o, operandos e operadores
			if (texto[i] == '=') // atribui��o
				atribu++;
				
			else if (((isalpha(texto[i])) || (isdigit(texto[i]))) && (atribu == 0)){ //operandos
				
				while ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) // caso operando seja de v�rios caracteres
					i++;
				operando++;
			}
			else if ((texto[i] != ' ') && (atribu == 0)) //caso seja operadores 
				operador++;
		}
		
		if ((operador > 0) || (operando > 1) || (atribu != 1)){ // se antes da atribui��o h� mais operandos que o poss�vel
		// e haja operadores ou operador de atribui��o a mais, � uma express�o invalida
			printf("\nERRO: N�o � uma express�o v�lida\n");
			system("PAUSE");
			inicio = false;
		} else { // se estiver tudo certo, zera variaveis para utilizar posteriormente
			operador = 0;
			operando = 0;
		}
	}
		
		
		if ((tamexc == false) && (inicio == true)){ // se o tamanho da express�o ou quantidade de operadores n�o exceder, continua
			
			for (i = 0; i <= tamstr-1; i++) { //looping para identifica��o de operadores, operandos e erros
							
					if (texto[i] == ' ') { // ignora espa�os em branco
					while(texto[i+1] == ' ')
						i++;
					}
			
					else if ((texto[i] == '*') || (texto[i] == '/') || (texto[i] == '+') || (texto[i] == '-')) { //identificar n�mero de operadores
						
						if ((texto[i+1] == ' ')) { //ignora espa�os em branco
							while(texto[i+1] == ' ')
								i++;
						} 
						
						if ((texto[i+1] == '*') || (texto[i+1] == '/') || (texto[i+1] == '+') || (texto[i+1] == '-')) { // se achar outro operador ap�s encontra o primeiro, � um erro
							errop1++;
							
						} else { // se n�o, continua
						operador++;
						
						}
					}

					else if	((isalpha(texto[i])) || (isdigit(texto[i]))) { // identificar operandos 
						
						if ((texto[i+1] == ' ')) { // ignora espa�os em branco
							while(texto[i+1] == ' ')
								i++;
								
							if ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) { //se houver um carater separado por espa�o em branco, � um erro
								errop2++;
								
							} else { // se n�o, continua
								operando++;
							} 
							
						} else {
							
							while ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) // se houver operando de v�rios caracteres, pula os caracter
								i++;
								
							if (texto [i+1] == ' ') { // ignora os espa�os em branco
								
								while(texto[i+1] == ' ')
									i++;
								
								if ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) { // se achar outro caracter ap�s o anterior, � um erro
								errop2++;
								
								}else { // se n�o, continua
								operando++;
								} 
								
							} else { // se n�o, continua
							operando++;
							}
						}	
					}	
			}
			
			// mostrar os resultados finais da an�lise da express�o 
			if ((errop1 != 0) && (errop2 == 0)){
				printf("\nERRO: H� operadores demais entre os operandos\n");
				system("PAUSE");
			} else if ((errop2 != 0) && (errop1 == 0)){
				printf("\nERRO: H� operandos separados por espa�o em branco\n");
				system("PAUSE");
			} else if ((errop2 != 0) && (errop1 != 0)){
				printf("\nERRO: H� um problema com operandos e operadores");
				printf("\nOperadores demais entre os operandos e");
				printf(" operandos separados por espa�o em branco\n");
				system("PAUSE");
			} else if ((errop1 == 0) && (errop2 == 0)){
				
				if ((operador > 2) && (operando < 5)){
					printf("\nERRO: H� operadores demais\n");
					system("PAUSE");
				} else if ((operador < 3) && (operando > 4)){
					printf("\nERRO: H� operandos demais\n");
					system("PAUSE");
				} else if ((operador > 2) && (operando > 4)){
					printf("\nERRO: H� operadores e operandos demais\n");
					system("PAUSE");
				} else if (operando > 1){
					printf("\nN�o h� problemas na express�o\n");
					
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
								while ((isalpha(texto[i+1])) || (isdigit(texto[i+1])))
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
								while ((isdigit(texto[i+1])) || (isalpha(texto[i+1]))) //percorre esse n�mero at� acabar as casas decimais
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
	}
} 
					system("PAUSE");	
				} else {
					printf("\nERRO: N�o � uma express�o v�lida\n");
					system("PAUSE");
				}
			}
		}		
	} 			 

