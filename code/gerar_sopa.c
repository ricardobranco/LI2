#include <stdio.h>
#include <string.h>
#include "interpretador.h"
#include "board.h"
#include "cadeias.h"


void gerar_sopa_serpente(BOARD board){

}

void gerar_sopa_cavalo(){

}

void gerar_sopa(BOARD board,char* modo){
	int i,j;
	for(i = 0; i<board->nl;i++){
		for(j = 0; j <board->nc;j++){
			board->board[i][j]=NULL;
		}
	}
	if(!cad_comparar(modo,"serpente")){
		gerar_sopa_serpente(board);
	}
	else if(!cad_comparar(modo,"cavalo")){
		gerar_sopa_cavalo();
	}
}


int main() {
	char* readline = NULL;
	char* modo = NULL;
	BOARD board = NULL;
	int nl,nc;

	/*modo=rl_gets("Modo> ");
	readline=rl_gets("Numero de Linhas e de Colunas> ");
	sscanf(readline,"%d %d",&nl,&nc);
	board = board_init(nl,nc);
	readline= rl_gets("Palavras> ");
	DAG_load(dag,readline);
	gerar_sopa(board,dag,modo);*/
	return 0;
}
