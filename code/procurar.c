#include <stdio.h>
#include <string.h>
#include "interpretador.h"
#include "board.h"
#include "cadeias.h"
#include "dictionary.h"

int main() {
	BOARD board = NULL;
	int npares,i,j,cindex,lindex;
	char* readline = NULL;
	char *finalWord = NULL;
	char *strtokRes = NULL;

	DICIONARIO dic = dicionario_init();
	DICIONARIO palavras = dicionario_init();

	dicionario_load(dic,"dicio.txt");
	readline= rl_gets("Sopa de Letras> ");
	board = board_load(readline);
	lindex = cindex = 0;








	while((readline=rl_gets("Numero de Pares> "))!=NULL){
		sscanf(readline,"%d",&npares);
		finalWord = (char*) malloc(sizeof(char)*npares+1);
		readline=rl_gets("Coordenadas> ");
		strtokRes = strtok(readline," ");

		for(i = 0,j=0;strtokRes && i<(npares*2);i++){
			if(i%2==1){
				cindex = atoi(strtokRes);
				finalWord[j]=board->board[lindex-1][cindex-1];
				j++;
			}
			else{
				lindex = atoi(strtokRes);
			}
			strtokRes=strtok(NULL," ");
		}
		finalWord[j]='\0';
		if(palavra_existe(dic,finalWord)){
			printf("SUCESSO\n");
		}
		else{
			printf("INSUCESSO\n");
		}
	}
	return 0;
}
