#include "board.h"


BOARD board_init(int nl, int nc){
	BOARD board = (BOARD) malloc(sizeof(struct struct_board));
	board->board = (char**) malloc(sizeof(char)*nl*nc);
	board->nl = nl;
	board->nc = nc;
	return board;
}
