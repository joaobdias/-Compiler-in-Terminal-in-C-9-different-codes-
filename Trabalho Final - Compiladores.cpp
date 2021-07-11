#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>            
#include <stdbool.h>

int main () {

setlocale(LC_ALL,"Portuguese");

	while (1) {
		int pos = 0, posc = 0, tamstr = 0, i = 0, j = 0, k = 0, aux = 0, erroest = 0, errop = 0;
		bool sair = false, cond = false, comando = false, condif = false;
		char comandos [31][31], vetaux [15], vetaux2[31], s;
		
		do {
		
			//looping para receber as express�es
			do { 
				i=0;
				system("cls");
				printf("Digite a express�o:");
    			fflush(stdin); // limpa buffer de entrada de dados
    			gets(comandos[pos]); // recebe o texto escrito e armazena em texto
    			tamstr = strlen(comandos[pos]); // tamanho exato da string
    			if (tamstr > 32) {
    				printf("Tamanho da express�o ultrapassado\n");
    				system("pause");
    			}

			} while (tamstr > 32);
				
			// looping para saber quantas express�es ser�o escritas	
			do {
			s = ' ';
			system("cls");
			i=0;
			printf("Express�es escritas: \n");
			
			while (i <= pos ){ //impress�o na tela das express�es j� escritas pelo usu�rio
				printf("%s\n", comandos[i]);
				i++;
			}
			
			printf("\nDeseja escrever mais express�es? Tecle s para sim ou n para n�o\n");
			s = getch();
			
				if ((s != 's') && (s != 'n')) //condi��o para verificar a validade da escrita do usu�rio
					printf("\nERRO: N�o � uma op��o v�lida.\n");
				else if (s == 's') {
					pos++;
					sair = false;	
				} else if (s == 'n')
					sair = true;
			
					
			} while ((s != 's') && (s != 'n'));
			
			
		} while ((!sair) && (pos < 32)); 
		
		char comandosc [pos][63]; // cria��o da matriz auxiliar das express�es
						
		for (i = 0; i <= pos; i++) { // looping para percorrer as express�es da matriz
			tamstr = strlen(comandos[pos]); //tamanho da express�o do momento para limitar o looping
			//limpeza de variaveis que ser�o utilizadas
			k = 0;
			comando = false;
			cond = false;
			memset(vetaux2, 0, 31);

			for (j = 0; j <= tamstr-1; j++) { //percore os elementos da express�o atual
			k = 0;
			
				if (comandos[i][j] == ' '){ //se achar espa�o em branco, pula
					while (comandos[i][j+1] == ' ')
						j++;
						
				} else if ((comandos[i][j] == 'W') || (comandos[i][j] == 'I')) { // se achar um W ou I
				
					if (!comando) {

					if (comandos[i][j] == 'W') //determina se � while ou if
						condif = false;
					else 
						condif = true;
						
					while (comandos[i][j+1] == ' ')
						j++;
						
					if (((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) || (isdigit(comandos[i][j+1]))){ // se achar alguma variavel ou numero, continua
						vetaux[k] = comandos[i][j+1]; //armazena essa variavel ou numero em um vetor auxiliar
						k++;
						j++;
						while (comandos[i][j+1] == ' ')
							j++;
						
						if ((comandos[i][j+1] == '>') || (comandos[i][j+1] == '<') || (comandos[i][j+1] == '#')) { //se achar as atribui��es, continua
							vetaux[k] = comandos[i][j+1];//armazena simbolo em um vetor auxiliar
							k++;
							j++;	
							while (comandos[i][j+1] == ' ')
								j++;
								
							if (((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) || (isdigit(comandos[i][j+1]))) { // se achar outra variavel ou numero, continua
								vetaux[k] = comandos[i][j+1];
								k++;	
								j++;
								while (comandos[i][j+1] == ' ')
									j++;
								
								if (comandos[i][j+1] == '{') {
									j++; 
									aux = j;	
									while (comandos[i][aux+1] != '}')
										aux++;
										
									if (comandos[i][aux+1] == '}'){
										
											if (cond)
												errop++;
											cond = true;
											comando = true;
												
											if (!condif){ // determina o resultado em c
												if(strchr(comandos[i], '#') == NULL){
													//armazena no vetor auxiliar o caso while
													strcpy(vetaux2,comandos[i]);
													//as variaveis do vetor auxiliar viram string agora
													sprintf(vetaux2,"while (%c %c %c) {", vetaux[0],vetaux[1],vetaux[2]); //o % foi trocado pelo / para evitar bugs no program

												} else {
													//armazena no vetor auxiliar o caso while com o simbolo !=
													strcpy(vetaux2,comandos[i]);
													//as variaveis do vetor auxiliar viram string agora
													sprintf(vetaux2,"while (%c != %c) {", vetaux[0],vetaux[1],vetaux[2]);
												}
												
											} else { // determina o resultado em c
												
												if(strchr(comandos[i], '#') == NULL){
													//caso do if
													strcpy(vetaux2,comandos[i]);
													sprintf(vetaux2,"if (%c %c %c) {", vetaux[0],vetaux[1],vetaux[2]); //o % foi trocado pelo / para evitar bugs no program

												} else {
													strcpy(vetaux2,comandos[i]);
													sprintf(vetaux2,"if (%c != %c) {", vetaux[0],vetaux[1],vetaux[2]);
												}
											}
												
											
									} else {
										errop++;
									}
									
								} else { 
									errop++;
								}
								
							} else {
								errop++;
							}
						} else {
							errop++;	
						}
					} else {
						errop++;
					}
				} else {
					erroest++;
				}

				} else if ((comandos[i][j] == 'G') || (comandos[i][j] == 'P')) { //se for G ou P 
				if (((!comando) && (!cond)) || ((comando) && (cond))) {
					
					if ((comandos[i][j] == 'G')) { // caso seja o G, futuro print f
						
						while (comandos[i][j+1] == ' ')
							j++;
						if ((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) { // mesma l�gica que o W e I
							vetaux[k] = comandos[i][j+1];// aramazena elemento no vetoraux
							k++;
							j++;
							while (comandos[i][j+1] == ' ')
								j++;
							if (((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) || (isdigit(comandos[i][j+1]))) 
								errop++;
								
									if (cond){
										// a string do while ou if, se juntam ao scanf e vira o resultado final
										sprintf(comandosc[posc],"%s scanf('/d', &%c); }", vetaux2,vetaux[0]); //o % foi trocado pelo / para evitar bugs no programa
										posc++; //posi��o no vetor de comandosc � incrementado
									} else {
										sprintf(comandosc[posc],"scanf('/d', &%c);", vetaux[0]); //o % foi trocado pelo / para evitar bugs no programa
										posc++;
										comando = true;
									}
						} else {
							errop++;
						}
						
					} else if (comandos[i][j] == 'P') { // mesma l�gica que o passo anterior mas para caso seja print
						while (comandos[i][j+1] == ' ')
							j++;
						if ((isdigit(comandos[i][j+1])) || ((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) ) {
							vetaux[k] = comandos[i][j+1];
							k++;
							j++;
							while (comandos[i][j+1] == ' ')
								j++;
								
								if (((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) || (isdigit(comandos[i][j+1]))) 
									errop++;

									if (cond) {
										sprintf(comandosc[posc],"%s printf('/d', %c); }",vetaux2 ,vetaux[0]); //o % foi trocado pelo / para evitar bugs no programa
										posc++;
									} else {
										sprintf(comandosc[posc],"printf('/d', %c);", vetaux[0]);
										posc++;
										comando = true;
									}
						} 
				 } 
					
				} else 
					erroest++;
			
				} else if ((comandos[i][j] == '+') || (comandos[i][j] == '-') || (comandos[i][j] == '*') || (comandos[i][j] == '/') || (comandos[i][j] == '%')) {
					// possui a mesma l�gica que os casos anteriores, mas para casos de */-+% abc
					if (((!comando) && (!cond)) || ((comando) && (cond))) {
					vetaux[k] = comandos[i][j];
					k++;
					while (comandos[i][j+1] == ' ')
						j++;
						
					if (((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) || (isdigit(comandos[i][j+1]))){
						vetaux[k] = comandos[i][j+1];
						k++;
						j++;
						while (comandos[i][j+1] == ' ')
							j++;
						if (((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) || (isdigit(comandos[i][j+1]))) {
							vetaux[k] = comandos[i][j+1];
							k++;
							j++;
							while (comandos[i][j+1] == ' ')
								j++;
								
							if (((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) || (isdigit(comandos[i][j+1]))) {
								vetaux[k] = comandos[i][j+1];
								k++;
									if (cond)
									cond = false;
									else 
									comando = true;

								sprintf(comandosc[posc],"%c = %c %c %c;", vetaux[1], vetaux[2], vetaux[0], vetaux[3]);
								posc++;
										
							} else {
								errop++;
							}
						} else {
							errop++;
						}
											
					} else {
						errop++;
					}
					
				} else {

					erroest++;
				}
					
			
				} else if(comandos[i][j] == '=') {
				
				if ((!comando) && (!cond)) {
					while (comandos[i][j+1] == ' ')
						j++;
					if (((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) || (isdigit(comandos[i][j+1]))) {
						vetaux[k] = comandos[i][j+1];
						k++;
						j++;
						while (comandos[i][j+1] == ' ')
							j++;
						if (((islower(comandos[i][j+1])) && (isalpha(comandos[i][j+1]))) || (isdigit(comandos[i][j+1]))) {
							vetaux[k] = comandos[i][j+1];
							k++;
							j++;
							sprintf(comandosc[posc],"%c = %c;", vetaux[0], vetaux[1]);
							posc++;
							comando = true;
						
						} else {
							errop++;
						}
					} else
						errop++;
				} else {
					erroest++;
				}
				}   
			}
		} 
		
		
		// baseado no erros encontrados nos passos anteriores, aqui � definido se est� certo ou errado

		if ((errop > 0) && (erroest > 0)){
			printf("\nH� erros sint�ticos e estruturais no c�digo.\n");
		} else if ((errop > 0) && (erroest == 0)){
			printf("\nH� erros sint�ticos no c�digo.\n");
		} else if ((errop == 0) && (erroest > 0)){
			printf("\nH� erros estruturais no c�digo.\n");
		} else {
			
			printf("\nExpress�es em C: \n");
			i = 0;
			while (i <= pos){
				printf("%s\n", comandosc[i]);
				i++;
			}
			
		}
		
		system("pause");
	
	}
	
	return 0;
}


								

