#include "board.h"

BOARD board_init(int nl, int nc){
	int i;

	BOARD board = (BOARD) malloc(sizeof(struct struct_board));
	board->board = (char**) malloc(sizeof(char*)*nl);
	for(i = 0; i < nl; i++){
		board->board[i]=malloc(sizeof(char)*nc+1);
	}
	board->nl = nl;
	board->nc = nc;
	return board;
}

int add_row(char* row,int pos,BOARD board){
	cad_copiar(row,board->board[pos]);
	return cad_tamanho(board->board[pos]);
}

void print(BOARD board){
	int i;
	for(i = 0; i < board->nl; i++)
		printf("%s\n",board->board[i]);
}

BOARD board_load(char file[]){
	char readline[20];
	char* row = NULL;
	int nl,nc,i;
	BOARD board = NULL;
	FILE* f = NULL;

	f = fopen(file, "rt");

	fgets(readline,sizeof(readline)-2,f);
	sscanf(readline,"%d %d",&nl, &nc);

	board = board_init(nl,nc);
	row = (char*) malloc(sizeof(char)*nc+1);

	i=0;

	while (fgets(readline,sizeof(readline)-2,f) && i < nl){
		cad_mover(readline,row,nc+1);
		add_row(row,i,board);
		i++;
	}
	fclose(f);
	return board;
}
