#include <stdio.h>
#include <string.h>
#include "interpretador.h"
#include "board.h"
#include "cadeias.h"
#include "dictionary.h"

/**
 @brief Função que encontra todas as palavras num tabuleiro de forma serpenteada
 @param board Tabuleiro onde se encontram as palavras 'escondidas'
 @param dic Dicionario com todas as palavras da lingua portuguesa
 @param x Inteiro referente a linha em que se começa a procura
 @param y Inteiro referente a coluna em que se começa a procura
 @param res Dicionario com as palavras encontradas até ao momento
 @param prefix String com a string a construir
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
void encontrar_todas_serpente(BOARD board,DICIONARIO dic, int x, int y, DICIONARIO res, char* prefix){
	int xmin,xmax,ymin,ymax;
	int i,j;
	int len;
	char *newPrefix = NULL;
	char old;
	len = cad_tamanho(prefix);

	if(palavra_existe(dic,prefix)){
		if(!palavra_existe(res,prefix))
			add_palavra(res,prefix);
	}

	old = board->board[x][y];
	board->board[x][y] = 0;

	xmin = x-1<0?0:x-1;
	xmax = x+1>board->nl-1?board->nl-1:x+1;
	ymin = y-1<0?0:y-1;
	ymax = y+1>board->nc-1?board->nc-1:y+1;

	for(i = xmin;i <= xmax;i++){
		for(j = ymin; j <= ymax;j++){
			if(board->board[i][j]){
				newPrefix= (char*) malloc(sizeof(char)*len+2);
				cad_copiar(prefix,newPrefix);
				newPrefix[len]=board->board[i][j];
				newPrefix[len+1]='\0';

				if(palavra_prefix(dic,newPrefix))
					encontrar_todas_serpente(board,dic,i,j,res,newPrefix);

				free(newPrefix);
			}
		}
	}
	board->board[x][y] = old;
}


/**
 @brief Função que encontra todas as palavras num tabuleiro atraves do salto de cavalo
 @param board Tabuleiro onde se encontram as palavras 'escondidas'
 @param dic Dicionario com todas as palavras da lingua portuguesa
 @param x Inteiro referente a linha em que se começa a procura
 @param y Inteiro referente a coluna em que se começa a procura
 @param res Dicionario com as palavras encontradas até ao momento
 @param prefix String com a string a construir
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
void encontrar_todas_cavalo(BOARD board,DICIONARIO dic, int x, int y, DICIONARIO res, char* prefix){
	int xmin,xmax,ymin,ymax;
	int i,j;
	int len;
	char *newPrefix = NULL;
	char old;

	len = cad_tamanho(prefix);

	if(palavra_existe(dic,prefix)){
		if(!palavra_existe(res,prefix))
			add_palavra(res,prefix);
	}

	old = board->board[x][y];
	board->board[x][y] = 0;

	xmin = x-2;
	xmax = x+2;
	ymin = y-2;
	ymax = y+2;
	for(i = xmin;i <= xmax;i++){
		for(j = ymin; j <= ymax;j++){
			if(i >= 0 && i < board->nl && j >= 0 && j < board->nc && i != x && j != y){
				if(((i == xmin || i == xmax) && ( j == y-1 || j == y+1))||((i == x-1 || i == x+1) && ( j == ymin || j == ymax))){
					if(board->board[i][j]){
						newPrefix= (char*) malloc(sizeof(char)*len+2);
						cad_copiar(prefix,newPrefix);
						newPrefix[len]=board->board[i][j];
						newPrefix[len+1]='\0';
						if(palavra_prefix(dic,newPrefix))
							encontrar_todas_cavalo(board,dic,i,j,res,newPrefix);
						free(newPrefix);
					}
				}
			}
		}
	}
	board->board[x][y] = old;
}


/**
 @brief Função que encontra todas as palavras num tabuleiro
 @param board Tabuleiro onde se encontram as palavras 'escondidas'
 @param dic Dicionario com todas as palavras da lingua portuguesa
 @param modo String com o modo de procura (serpente ou cavalo)
 @returns Dicionario com todas as palavras encontradas
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
DICIONARIO encontrar_todas(BOARD board,DICIONARIO dic, char modo[]){
	DICIONARIO res = dicionario_init();
	char* prefix = (char*) malloc(sizeof(char)+1);
	int i,j;
	for(i = 0; i < board->nl; i++){
		for(j = 0; j < board->nc; j++){
			sprintf(prefix,"%c",board->board[i][j]);
			if(!cad_comparar(modo,"serpente")){
				encontrar_todas_serpente(board,dic,i,j,res,prefix);
			}else if(!cad_comparar(modo,"cavalo")){
				encontrar_todas_cavalo(board,dic,i,j,res,prefix);
			}
		}
	}
	free(prefix);
	return res;
}


int main() {
	char* readline = NULL;
	char* modo = NULL;
	int nl,nc,i;
	BOARD board = NULL;
	DICIONARIO res;
	DICIONARIO dic = dicionario_init();

	dicionario_load(dic,"dicio.txt");

	modo=rl_gets("");
	readline=rl_gets("");
	sscanf(readline,"%d %d",&nl,&nc);
	board = board_init(nl,nc);
	for(i = 0; i<nl; i++){
		readline=rl_gets("");
		add_row(readline,i,board);
	}
	res=encontrar_todas(board,dic,modo);
	dicionario_print(res);
	return 0;
}
