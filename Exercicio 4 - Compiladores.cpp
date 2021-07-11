#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

void inicializador_de_vetor(char *texto){ // função para iniciar todos elementos do vetor char com espaços vazios
	int aux = 0;
	while(aux < 127){ // looping para percorrer todo o vetor char
		*texto = '\0'; // \0 significa espaço vazio
		texto++; // passa para o próximo elemento do vetor
		aux++; // incrementa o auxilar
	}
}

int main () {
	
	setlocale(LC_ALL,".OCP"); //set locale que permite que o printf mostre acentuação
	char texto[127],textoaux[127]; // criação das strings
  	int loop = 1; //variavel de controle do programa
  	 
  	
  while(loop == 1){ // looping para programa continuar funcionando
  	system("cls"); //limpar tela
  	int aux = 0,auxtwo = 0,aux3 = 0,tamstr = -1,escolha,inicio = 0,fim = 0,erro =0; //declaração das variaveis
    inicializador_de_vetor(texto); //inicializa os vetores criados com todos os elementos com espaço em branco
	inicializador_de_vetor(textoaux); //mesma coisa com o vetor aux, que será a string sem os comentário

	printf("Menu\n"); // Mostra as opções do menu do programa para o usuário
    printf("1- O programa para verificar comentarios\n");
    printf("2- Sair do programa\n");
    scanf("%i",&escolha); //recebe a escolha do usuário
    system("cls"); //limpar tela
   
    switch(escolha){ // de acordo com a escolha, o programa continua
      case 1:
        printf("Digite a frase para verificar: ");
        fflush(stdin); //limpa o buffer de escrita do teclado STANDARD INPUT
        gets(texto); //vetor texto recebe string escrita pelo usuário
	    
	    while(texto[aux] != '\0'){ //para tamstr armazenar a quantidade de caracteres da string digitada pelo usuario
				tamstr++; //variaveis auxiliares
				aux++;
			} aux = 0; //aux recebe zero para posterior utilização 
		
	    for(aux = 0;aux <= tamstr;aux++) {  //for para o programa começar a transformar o texto escrito
	    
			if (texto[aux] == '/') { //verifica a existência de uma barra, dessa forma, o usuario provavelmente quer digitar um comentário
				if (texto[aux+1] == '/') { //verifica se há um outro / a frente, sendo um comentário //
					aux = tamstr; // o looping para aqui mesmo					
			} 
				else if (texto[aux+1] == '*') { // se depois do /, tiver um *
					inicio = aux; // marca o inicio do bloco
					aux = aux +2; //pula para a posição após o /*
	
						while(1) { // percorre o resto da string em busca do final do bloco
							if ((texto[aux] == '*') && (texto[aux+1] == '/'))
								break; //achou o final, termina aqui
				
							 if ((texto[aux] == '/') || (texto[aux] == '*')) { // se achou um / ou *, a pessoa estava tentando escrever comentário de bloco
								printf("\nUm comentario de blocos foi digitado sem finalizar");
								printf("\nNo local [%d] talvez queira usar '*/' ao inves de: '%c'\n'",aux,texto[aux]);
								erro = 1;
								system("PAUSE");
								break;
						}
							else if (aux >= tamstr) { // se percorrer todo o resto da string e não achar o final do bloco
								printf("\nSINTAXE INCORRETA");
								printf("\nNo local [%d] foi iniciado um comentario de bloco, mas nao foi finalizado\n",inicio,texto[aux],texto[aux+1]);
								erro = 1;
								system("PAUSE");
								break;
							}
								aux++; // continua percorrendo a string
						}
								if (erro == 0) { //se não houve erro e saiu do looping, logo, achou o */, marca o final do bloco
								fim = aux+2; 
								aux++; 
			  				}	
						}
							
				else if (fim == 0) { //se não tiver achado nada após o / escrito, nem / nem *
					printf("\nSINTAXE INCORRETA");
					printf("\nNo local [%d] foi digitado: '%c'",aux,texto[aux]);
					printf("\nTalvez queria usar um comentario de barras, digite '//' ou comentario de blocos '/*...*/'\n");
					aux = tamstr; //termina o looping aqui
					erro++;
					system("pause");
		}
	} 
				else { // se ainda nõa tiver achado o nenhum /, escreve na string auxiliar
					textoaux[auxtwo] = texto[aux];
					auxtwo++;
	}
} 
		 
		auxtwo = 0; //auxtwo recebe 0 para posterior utilização
		if ((inicio == 0) && (erro == 0)) { //condição para mostrar textoaux caso seja // ou sem comentários 
	    printf("\nA frase digitada: %s\n",textoaux);
	    system("PAUSE");
	    break;
} 
		else if ((fim != 0) && (erro == 0)){ //caso haja um inicio /* e fim */
		for (aux = 0; aux < inicio; aux++) { // looping para armazenar no vetor aux todos os carácters até o inicio do comentario
		textoaux[auxtwo] = texto[aux];
		auxtwo++;
}		
		for(aux = fim; aux <= tamstr; aux++) { //looping para armazenar no vetor aux todos os carácters do fim até o final da string escrita pelo usuario
		textoaux[auxtwo] = texto[aux];
		auxtwo++;
}
		printf("\nA frase digitada: %s\n",textoaux); // mostra na tela a frase transformada
		system("PAUSE");
		break;
}
		break;
  	  case 2: //caso queria sair do programa
  	  	printf("Obrigado por utilizar o nosso programa!\n");
  	  	loop = 0;
  	  	break;
  	  default:
  	  	printf("ESCOLHA INVALIDA\n");
  	  	system("pause");
  	  	break;
	}
  }
return 0;
}
