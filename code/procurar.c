#include <stdio.h>
#include <string.h>
#include <curses.h>
#include "interpretador.h"
#include "board.h"
#include "cadeias.h"
#include "dictionary.h"
#include "jogada.h"


int procurar_print(BOARD board,int x,int y,LISTA_JOGADAS jogadas){
	int i,j;


	for ( i = 0; i < board->nl; ++i){
		for ( j = 0; j < board->nc; ++j){
			if (i == x && j == y)
			{

				init_pair(1,  COLOR_BLUE,    COLOR_WHITE);
				color_set(1, NULL);
			}
			else{
				if (jogadas_contem(jogadas,i,j))
				{

				init_pair(2,  COLOR_RED,   COLOR_WHITE);
				color_set(2, NULL);
				}
				else{
					init_pair(3,  COLOR_BLACK,   COLOR_WHITE);
					color_set(3, NULL);
				}
			}

			mvprintw(i,j,"%c",board->board[i][j]);

		}
	}
	return i;
}

int valida_jogada(BOARD board,DICIONARIO dic,DICIONARIO palavras,LISTA_JOGADAS jogadas,char* finalWord, int len ){
	int i=0;
	int res = 0;
	LISTA_JOGADAS aux = jogadas;
	while(aux){
		finalWord[i++] = board->board[aux->x][aux->y];
		aux = aux->next;
	}
	finalWord[len] = '\0';
	if(palavra_existe(dic,finalWord) && !palavra_existe(palavras,finalWord)){
		add_palavra(palavras,finalWord);
		res = 1;
	}
	return res;
}

int main(){
	WINDOW * mainwin;
	BOARD board = NULL;
	DICIONARIO dic = dicionario_init();
	DICIONARIO palavras = dicionario_init();
	LISTA_JOGADAS jogadas = NULL;
	char* readline = NULL;
	char* finalWord = NULL;
	int key;
	int finalWord_len;
	int currentX=0, currentY=0;
	int jogada_validada = 0;
	dicionario_load(dic,"dicio.txt");

    readline= rl_gets("Sopa de Letras> ");
    board = board_load(readline);

    if ( (mainwin = initscr()) == NULL ) {
	fprintf(stderr, "Error initializing ncurses.\n");
	exit(EXIT_FAILURE);
    }
    noecho();
    keypad(mainwin, TRUE);
    start_color();
    procurar_print(board,currentX,currentY,jogadas);
	mvaddstr(board->nl, 0, "Setas para jogar,'J' para jogar,'C' para confirmar,'L' para limpar, 'S' para sair");
	refresh();

    while ( (key = getch()) != 's' ) {
		switch(key){
			case KEY_DOWN:
				currentX++;
				if(currentX==board->nl)
					currentX--;
				break;
			case KEY_UP:
				currentX--;
				if(currentX==-1)
					currentX++;
				break;
			case KEY_LEFT:
				currentY--;
				if(currentY==-1)
					currentY++;
				break;
			case KEY_RIGHT:
				currentY++;
				if(currentY==board->nc)
					currentY--;
				break;
			case 'j':
				if(!jogadas_contem(jogadas,currentX,currentY)){
					jogadas = jogadas_add_jogada(jogadas,currentX,currentY);
				}
				break;
			case 'l':
				jogadas_free(jogadas);
				jogadas = NULL;
				break;
			case 'c':
				finalWord_len = jogadas_tamanho(jogadas);
				finalWord = (char*) malloc(sizeof(char)*finalWord_len+1);
				jogada_validada = valida_jogada(board,dic,palavras,jogadas,finalWord,finalWord_len);
				break;
			default:
				break;
		}
		procurar_print(board,currentX,currentY,jogadas);
		if(jogada_validada){
			init_pair(4,  COLOR_GREEN,   COLOR_WHITE);
			color_set(4, NULL);
			mvprintw(board->nl+1,0,"Encontrou:%s",finalWord);
			jogadas_free(jogadas);
			jogadas = NULL;
			jogada_validada = 0;
		}else{
			mvprintw(board->nl+1,0,"");
		}
		if(finalWord){
			free(finalWord);
			finalWord = NULL;
		}
		refresh();
	}
	delwin(mainwin);
    endwin();

    return 0;
}
