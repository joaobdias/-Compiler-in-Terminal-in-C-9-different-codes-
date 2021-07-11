#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

void inicializador_de_vetor(char *texto){ // fun��o para iniciar todos elementos do vetor char com espa�os vazios
	int aux = 0;
	while(aux < 127){ // looping para percorrer todo o vetor char
		*texto = '\0'; // \0 significa espa�o vazio
		texto++; // passa para o pr�ximo elemento do vetor
		aux++; // incrementa o auxilar
	}
}

int main () {
	
	setlocale(LC_ALL,".OCP"); //set locale que permite que o printf mostre acentua��o
	char texto[127],textoaux[127]; // cria��o das strings
  	int loop = 1; //variavel de controle do programa
  	
  while(loop == 1){ // looping para programa continuar funcionando
  	system("cls"); //limpar tela
  	int aux = 0,auxtwo = 0,tamstr = -1,escolha,inicio = 0,fim = 0,erro =0; //declara��o das variaveis
    inicializador_de_vetor(texto); //inicializa os vetores criados com todos os elementos com espa�o em branco
	inicializador_de_vetor(textoaux); //mesma coisa com o vetor aux, que ser� a string sem os coment�rios
	
	printf("Menu\n"); // Mostra as op��es do menu do programa para o usu�rio
    printf("1- O programa para verificar comentarios\n");
    printf("2- Sair do programa\n");
    scanf("%i",&escolha); //recebe a escolha do usu�rio
    system("cls"); //limpar tela
   
    switch(escolha){ // de acordo com a escolha, o programa continua
      case 1:
        printf("Digite a frase para verificar: ");
        fflush(stdin); //limpa o buffer de escrita do teclado STANDARD INPUT
        gets(texto); //vetor texto recebe string escrita pelo usu�rio
	    
	    while(texto[aux] != '\0'){ //para tamstr armazenar a quantidade de caracteres da string digitada pelo usuario
				tamstr++; //variaveis auxiliares
				aux++;
			} aux = 0; //aux recebe zero para posterior utiliza��o 
		
	    for(aux = 0;aux <= tamstr;aux++) {  //for para o programa come�ar a transformar o texto escrito
			if((texto[aux] == '/') && (texto[aux+1]=='/') ) { //caso  seja comentario do tipo //
				aux = tamstr; //looping de inser��o de elementos no vetor auxiliar termina
} 

			else if ((texto[aux] == '/') && (texto[aux+1] == '*')){ // caso seja coment�rio do tipo /**/
				inicio = aux; //inicio representa quando come�a o coment�rio do texto inserido pelo usuario
				while(1){ //looping para percorrer todos os elementos do vetor em busca do final do coment�rio */
					if(((texto[aux] == '*') && (texto[aux+1] == '/')))
						break; //looping termina na hora que encontra o final do coment�rio
					else if (aux >= tamstr){
						printf("\nTEXTO INSERIDO INVALIDO\n");
						erro = 1;
						system("PAUSE");
						break;
					}
					aux++; //incrementa para ir buscando os pr�ximos caracteres do vetor
				}
				if (erro == 0){
				fim = aux+2; //fim representa quando termina o coment�rio do texto inserido pelo usu�rio
				aux++; //usado para pular do car�cter * para o /
			  }
			}
  			else {
			  textoaux[auxtwo] = texto[aux]; // caso n�o encontre // ou /*, o car�cter do momento ser� inserido no vetor auxiliar
			  auxtwo++; //incrementa a posi��o no vetor auxiliar para posterior inser��o de elemento
			}
 		} auxtwo = 0; //auxtwo recebe 0 para posterior utiliza��o
		
		if (inicio == 0) { //condi��o para mostrar textoaux caso seja // ou sem coment�rios 
	    printf("\nA frase digitada: %s\n",textoaux);
	    system("PAUSE");
	    break;
} 
		else if (fim != 0){ //caso haja um inicio /* e fim */
		for (aux = 0; aux < inicio; aux++) { // looping para armazenar no vetor aux todos os car�cters at� o inicio do comentario
		textoaux[auxtwo] = texto[aux];
		auxtwo++;
}		
		for(aux = fim; aux <= tamstr; aux++) { //looping para armazenar no vetor aux todos os car�cters do fim at� o final da string escrita pelo usuario
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
