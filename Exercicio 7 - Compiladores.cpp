#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 63

int main(){
	
	setlocale(LC_ALL,"Portuguese"); 

	while (1) { //looping para programa se repetir
	
	//cria��o das variaveis utilizadas no programa e limpar tela 	
	system("cls");
	char texto[MAX];
	int tamstr, i, aux, pospar1 = 0, pospar2 = 0, erroest = 0, errop = 0, opera = 0, operando = 0,delimi=0;
	bool tamexc = false, seif = false, sefor = false, sewhile = false, erroini = false, delim = false, atribu = false;
		
	//determina��o da express�o que ser� analisada	
	printf("Digite a c�digo fonte:");
    fflush(stdin); // limpa buffer de entrada de dados
    gets(texto); // recebe o texto escrito e armazena em texto
    tamstr = strlen(texto); // tamanho exato da string
	
		if (tamstr >= 32){ //se o tamanho da string exceder o limite da variavel texto
    		printf("\nERRO: Tamanho da express�o ultrapassa limite m�ximo de %d caracteres\n",MAX+1);
    		tamexc = true; //se execeder, n�o havera mais nada ap�s aqui
		}
		
		if (tamexc == false) { // se n�o ultrapassou o limite, continua
			for (i = 0; i <= tamstr-1; i++) { //looping para ver qual comando � , if, while ou for, ele procura em cada caracter da string
				
				if (texto[i] == ' '){ // se achar espa�o em branco, pula
					while(texto[i+1] == ' ')
						i++;
							
				} else if ((texto[i] == 'i') && (texto[i+1] == 'f')){ //se achar o comando if, continua e verifica se foi escrito corretamente
					
					i++;
					
					if(texto[i+1] == ' '){ // pula espa�os em branco
						while(texto[i+1] == ' ')
							i++;	
					} 
					
					if (texto[i+1] == '('){ // se achar um parentesis, armazena sua posi��o em variavel
						pospar1 = i+1;
						aux = i;
						
						while ((texto[aux+1] != ')') && (aux <= tamstr-1)) // looping para achar o outro parentesis
							aux++;
							
						if (texto[aux+1] == ')'){ // se achar
							
							if ((seif == false) && (sefor == false) && (sewhile == false)){ // se j� nao tiver nenhuma outra fun��o
								pospar2 = aux+1; // armazena posi��o do segundo parentesis
								seif = true; //variavel booleana para caso if
								
							} else { //se j� houver outros comandos antes
								printf("\nERRO: H� comandos demais na express�o\n");
								i = tamstr; //looping termina por aqui para n�o desperdi�ar tempo
								erroini = true;	//variavel de controle para evitar continuar o programa tamb�m
							}
							
						} else { //caso nao ache o parentesis
							i = tamstr;
							printf("\nERRO: Estrutura do comando IF incorreta\n");
							erroini = true;
						}
						
					} else { // caso nao ache o primeiro parentesis
							i = tamstr;
							printf("\nERRO: Estrutura do comando IF incorreta\n");
							erroini = true;
					}
					
				} else if (((texto[i] == 'f') && (texto[i+1] == 'o') && (texto[i+2] == 'r'))){ //possui a mesma estrutura do caso if
					i+=2;
					
					if(texto[i+1] == ' '){
						while(texto[i+1] == ' ')
							i++;	
					} 
					
					if (texto[i+1] == '('){
						pospar1 = i+1;
						aux = i;
						
						while ((texto[aux+1] != ')') && (aux <= tamstr-1))
							aux++;
							
						if (texto[aux+1] == ')'){
				
							if ((seif == false) && (sefor == false) && (sewhile == false)){
								pospar2 = aux+1;
								sefor = true;
								
							} else {
								printf("\nERRO: H� comandos demais na express�o\n");
								i = tamstr;
								erroini = true;	
							}
							
						} else {
							printf("\nERRO: Estrutura do comando FOR incorreta\n");
							i = tamstr;
							erroini = true;
						}
						
					}  else {
							printf("\nERRO: Estrutura do comando FOR incorreta\n");
							i = tamstr;
							erroini = true;
					}
					
				} else if (((texto[i] == 'w') && (texto[i+1] == 'h') && (texto[i+2] == 'i') && (texto[i+3] == 'l') && (texto[i+4] == 'e'))){ //possui a mesma estrutura do caso if e for
					i +=4;
					
					if(texto[i+1] == ' '){
						while(texto[i+1] == ' ')
							i++;	
					} 
					
					if (texto[i+1] == '('){
						pospar1 = i+1;
						aux = i;
						
						while ((texto[aux+1] != ')') && (aux <= tamstr-1))
							aux++;
							
						if (texto[aux+1] == ')'){
							
							if ((seif == false) && (sefor == false) && (sewhile == false)){
								pospar2 = aux+1;
								sewhile = true;
								
							} else {
								printf("\nERRO: H� comandos demais na express�o\n");
								i = tamstr;
								erroini = true;	
							}
							
						} else {
							i = tamstr;
							printf("\nERRO: Estrutura do comando WHILE incorreta\n");
							erroini = true;
						}
						
					} else {
							i = tamstr;
							printf("\nERRO: Estrutura do comando WHILE incorreta\n");
							erroini = true;
					}
			
				} else if ((seif == false) && (sefor == false) && (sewhile == false)){ // caso n�o seja nenhum dos tres casos, n�o foi possivel achar nenhum comando
					 	
					i = tamstr;
					printf("\nERRO: n�o foi poss�vel identificar um comando v�lido\n");
					erroini = true;
				
				} else if ((texto[i] == ';') && ((seif)||(sefor)||(sewhile))) { // caso ache o delimitador e exista algum comando, if, for ou while
					
					if (delim){ // se j� tiver achado um delimitador
						printf("\nERRO: H� delimitadores demais.");
						erroini = true;
						i = tamstr;
					}
					
					if (i > pospar2) //verifica delimitadores apenas ap�s o final do parentesis, estava dando problemas no caso for
						delim = true;
					else if (!sefor) { //o for pode  ter delimitadores dentro, os outros n�o
						printf("\nERRO: H� delimitadores em locais incorretos.");
						erroini = true;
						i = tamstr;
					}
				} 
			}
			
			if ((delim) && (!erroini)){ //caso exista um delimitador e n�o tenha dado erro, parte para verifica��o dentro do parentesis
				delim = false;
				for (i = pospar1; i <= pospar2; i++) { //looping para verificar caracters dentro do parentesis
						
					if (seif) { // caso tenha sido if no caso anterior
						
						if (texto[i] == ' ') { // pula espa�os em branco
							while (texto[i+1] == ' ') 
								i++;	
								
						// a partir daqui, a utiliza��o de duas variaveis importante para controlar os erros, o atribu que controla o erro dos operandos e
						//operadores, se certificando que estejam na ordem correta. E no caso do for, h� um reaproveitamento do delim, usado para verificar
						//os delimitadores internos do for, isso junto ao atribu		
						} else if ((isalpha(texto[i])) || (isdigit(texto[i]))) { // caso encontre um caracter
							
							if (!atribu){ //variavel de controle para verificar operandos apenas se for antes ou depois de um sinal de igualdade
								
								while (texto[i+1] == ' ') //pula espa�os em branco
									i++;
						
								if ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) //se ap�s pular (ou n�o pular), achar outro caracter, d� erro
									errop++;
						
								else { // se n�o der erro, caracter v�lido, adciona um operando e usa varaiavel de controle para evitar ler outro operador
								operando++;
								atribu = true;
								
									if (operando >= 3) // se o operador ultrapassar o limite, � um erro de estrutura
										erroest++;
								}
								
							} else if (errop == 0) // se entrar no looping do caracter e n�o for false no atribu, � um erro de estrutura
							
								erroest++;
				
						} else if ((texto[i] == '=') || (texto[i] == '<') || texto[i] == '>') { // caso encontre um simbolo de igualdade
							
							if (texto[i] == '='){ // esse sistema permite utilizar ==, <=, >= ou !=
								if ((texto[i-1] == '>')||(texto[i-1] == '<')||(texto[i-1] == '!')||(texto[i+1] == '=')) { 
								
									if (texto[i+1] == '=') //como encontra o primeiro =, aqui pula uma posi��o para evitar bugs
										i++;
										
									if (atribu) { //variavel de controle junto com o contador de operandos
										opera++;
										atribu = false;
									
									} else // caso nao seja a vez do operador
										erroest++;	
								} else 
									errop++;
									
							} else if ((texto[i] == '<') || ((texto[i] == '>'))) { //caso seja > ou <, pode ser que seja < ou > sozinhos, sem o =
								if (texto[i+1] == '='){
									i++;
									
									if (atribu) { // mesma estrutura que o caso anterior, mas caso seja < ou >
										opera++;
										atribu = false;
									
									} else 
										erroest++;
								} else { 
										
									if (atribu) {
										opera++;
										atribu = false;
									
									} else 
										erroest++;
								}
							}
						}

					} else if (sefor){ // caso seja for. Possui uma estrutura parecida, mas mais complexa, devido a quantidade de operandos e o uso de delimitadores
						if (texto[i] == ' '){
							while (texto[i+1] == ' ') 
								i++;	
								
						} else if ((isalpha(texto[i])) || (isdigit(texto[i]))) {
						if ((!atribu) && (!delim)){	//aqui, para contar os operadores, � necess�rio que tanto atribu quanto delim sejam falsos, para poder organizar
						//o uso dos operadores relacionais e os delimitadores internos
							while (texto[i+1] == ' ')
									i++;
						
							if ((isalpha(texto[i+1])) || (isdigit(texto[i+1]))) //se h� erro de mais caracteres
								errop++;
						
							else { //se n�o, soma o contador de operandos e ativa o atribu, impossibilitando de contar o operando novamente
								operando++;
								atribu = true;
								if (operando%2 == 0)
									delim = true;

							}
								
							} else { //se houver um acesso aqui mas n�o for sua vez, caso ainda falte delimitador ou operador, ele conta como erro
								erroest++;
							}
							
						} else if ((texto[i] == '=') || (texto[i] == '<') || texto[i] == '>') { //aqui verifica os operadores antes do primeiro
						//delimitador, que n�o verifica um valor, mas sim, decide o inicio do looping, depois do primeiro que funciona como no if
						//e while e depois do segundo, que utiliza apenas o ++ ou -- (escolha para facilitar)
							if((operando >= 2) && (operando <= 4)) { // caso seja o meio do for
						
							if (texto[i] == '='){ //pode ser ==, <=, >= ou !=. Aqui � igual ao if
								if ((texto[i-1] == '>')||(texto[i-1] == '<')||(texto[i-1] == '!')||(texto[i+1] == '=')) {
								
									if (texto[i+1] == '=')
										i++;
	
									if (atribu) {
										opera++;
										atribu = false;
									} else 
										erroest++;	
								} else { 
									atribu = false;
									errop++;
								}
									
							} else if ((texto[i] == '<') || ((texto[i] == '>'))) {
								if (texto[i+1] == '='){
									i++;
									
									if (atribu) {
										opera++;
										atribu = false;
									
									} else 
										erroest++;
								} else { 
										
									if (atribu) {
										opera++;
										atribu = false;
									
									} else 
										erroest++;
								}
							}
							
							} else if (operando < 2 ){ //caso seja antes do primeiro delimtiador, onde s� pode o = (para facilitar)
								if (texto[i] == '='){
									if ((texto[i-1] == '>')||(texto[i-1] == '<')||(texto[i-1] == '!')||(texto[i+1] == '=')) 		
										errop++; //da erro se houver algo alem do =
									else 
										if (atribu) {
											opera++;
											atribu = false;
										} else 
											erroest++;	
								}	
							} 
						
						} else if (((texto[i] == '+') || (texto[i] == '-')) && (operando > 4)) { // caso seja ap�s o segundo delimitador, s� pode ++ e --
							
							if (texto[i] == '+') { // caso seja ++
								
								if (texto[i+1] == '+'){
									if (atribu) {
										i++;
										opera++;
										atribu = false;
									} else 
										erroest++;	
								} else { 
									atribu = false;
									errop++;
								}
								
							} else if (texto[i] == '-') { //caso seja --
								
								if (texto[i+1] == '-'){
									if (atribu) {
										i++;
										opera++;
										atribu = false;
									} else 
										erroest++;	
								} else { 
									atribu = false;
									errop++;
								}
							}
						
							
							
						} else if (texto[i] == ';'){ //caso encontra os delimitadores, "desbloqueia" o calculo de operando e portanto, o de operadores tambem
							
							if (delim){
								atribu = false;
								delim = false;
								delimi++;
							} else 
								erroest++;
								
							if (delimi > 2)
								erroest++;
						}
						
					} else if (sewhile){ //a estrutura do while � a mesma que a do if
						
						if (texto[i] == ' ') {
							while (texto[i+1] == ' ') 
								i++;	
								
						} else if ((isalpha(texto[i])) || (isdigit(texto[i]))) {
							
							if (!atribu){
								
								while (texto[i+1] == ' ')
									i++;
						
								if ((isalpha(texto[i+1])) || (isdigit(texto[i+1])))
									errop++;
						
								else {
								operando++;
								atribu = true;
								
									if (operando >= 3)
										erroest++;
								}
								
							} else if (errop == 0) 
							
								erroest++;
				
						} else if ((texto[i] == '=') || (texto[i] == '<') || texto[i] == '>') {
							
							if (texto[i] == '='){
								if ((texto[i-1] == '>')||(texto[i-1] == '<')||(texto[i-1] == '!')||(texto[i+1] == '=')) {
								
									if (texto[i+1] == '=')
										i++;
										
									if (atribu) {
										opera++;
										atribu = false;
									
									} else 
										erroest++;	
								} else 
									errop++;
									
							} else if ((texto[i] == '<') || ((texto[i] == '>'))) {
								if (texto[i+1] == '='){
									i++;
									
									if (atribu) {
										opera++;
										atribu = false;
									
									} else 
										erroest++;
								} else { 
										
									if (atribu) {
										opera++;
										atribu = false;
									
									} else 
										erroest++;
								}
							}
						}
						
					}
				}
				
			} else if (!erroini) { // caso n�o encontre o delimitador no inicio, vem aqui direto
				
				if ((seif)||(sefor)||(sewhile)){
					printf("\nERRO: N�o foi encontrado um delimitador.");
					erroini = true;
				} else {
					printf("\nERRO: N�o h� uma express�o v�lida.");
					erroini = true;	
				}
			}  
			
			if ((seif) || (sewhile)) { //chegagem de erros devido a quantidade de operandos e operadores
				if((operando != 2) || (opera != 1))
					erroest++;
					
			} else { // for � separado por ter uma estrutura diferente
				if ((operando != 5) || (opera != 3) || (delimi != 2)) 
					erroest++;
			}

			if (!erroini){	//amostragem do resultado final da express�o, tudo dependendo dos erros encontrados na etapa de  dentro dos parentesis
				if ((erroest > 0) && (errop == 0))
					printf("\nERRO: H� erros na estrutura interna do comando");
				else if ((erroest == 0) && (errop > 0))
					printf("\nERRO: H� erros sint�ticos na estrutura interna do comando");
				else if ((erroest > 0) && (errop > 0))
					printf("\nERRO: H� erros na estrutura interna do comando");
				else if ((erroest == 0) && (errop == 0)) {
					printf("\nA express�o est� correta");
					printf("\nTABELA DE TOKENS:");
					for (i = 0; i <= tamstr - 1; i++){ //looping para mostrar os tokens 
						if (texto [i] != ' '){
		
						if ((texto[i] == '*') || (texto[i] == '/') || (texto[i] == '+') || (texto[i] == '-'))  
							printf("\n %c -> Operador Aritm�tico",texto[i]);
			
						else if (texto[i] == '=') { 
							if ((texto[i-1] == '!') || (texto[i-1] == '>') || (texto[i-1] == '<'))	
								printf("\n %c%c -> Operador de atribui��o",texto[i-1],texto[i]);	
							else if (texto[i+1] == '=')
								printf("\n %c%c -> Operador de atribui��o",texto[i],texto[i+1]);
							else if (sefor)
								printf("\n %c -> Operador de atribui��o",texto[i]);

						} else if ((texto[i] == '>') || (texto[i] == '<')) {
							if(texto[i+1] != '=')
								printf("\n %c -> Operador de atribui��o",texto[i]);
						
						}else if ((texto[i] == ')') || (texto[i] == '(') || (texto[i] == ';')) // caso n�o sejam espa�os em branco (ele n�o conta)
							printf("\n %c -> Pontua��o",texto[i]);

						else if(isalpha(texto[i])) { // caso seja uma vari�vel
							if (!isalpha(texto[i+1]))
								printf("\n %c -> Identificador",texto[i]);
							else {
								aux = i;
								while ((isalpha(texto[i+1])) || (isdigit(texto[i+1])))
									i++;
								printf("\n ");
								for (aux; aux <= i; aux++) //mostra os elementos do vetor como se fosse um n�mero s�
									printf("%c",texto[aux]);
								printf(" -> Palavra Reservada",texto[i]);
							}
							
						} else if (isdigit(texto[i])){
							printf("\n %c -> N�mero",texto[i]);
						} 
						}
					}
				}
			}
		}
	printf("\n");
	system("PAUSE");
}
	
	return 0;
}
