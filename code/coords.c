#include <stdio.h>
#include <string.h>
#include "interpretador.h"
#include "board.h"


int main() {

	int nl,nc,npares;
	int i,j;
	int cindex, lindex;

	char* readline = NULL;
	char* finalWord = NULL;
	char* strtokRes = NULL;

	BOARD board;

	readline=rl_gets("Numero de Linhas e de Colunas> ");
	sscanf(readline,"%d %d",&nl,&nc);
	board = board_init(nl,nc);


	for(i = 0; i<nl; i++){
		readline=rl_gets("Linha> ");
		add_row(readline,i,board);
	}


	readline=rl_gets("Numero de Pares> ");
	sscanf(readline,"%d",&npares);

	finalWord = (char*) malloc(sizeof(char)*npares+1);

	readline=rl_gets("Coordenadas> ");

	strtokRes = strtok(readline," ");
	lindex = cindex = 0;
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
	printf("%s\n",finalWord);
	return 0;
}


