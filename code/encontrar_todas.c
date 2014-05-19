#include <stdio.h>
#include "interpretador.h"
#include "board.h"





int main() {

	int nl,nc;
	int flag = 1;
	int i;

	char extra_args;
	char* readline = NULL;
	BOARD board;

	while(flag){
		while(!(readline=rl_gets("Numero de Linhas e de Colunas> ")));
		if(readline){
			if(sscanf(readline,"%d %d %s",&nl,&nc,&extra_args)==2)
				flag = 0;
		}
	}

	board = board_init(nl,nc);


	for(i = 0; i<nl; i++){
		readline=rl_gets("Linha> ")

	}


	return 0;
}
