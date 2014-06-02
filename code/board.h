#include "stdlib.h"
#include "cadeias.h"
#include "stdio.h"


/**
 @brief Estrutura de dados de um tabuleiro
 @details Estrutura de dados composta por dois inteiros que indicam as dimensões do tabuleiro e por uma matriz para armezenar as letras do tabuleiro
 @param nc Inteiro que indica o número de linhas do tabuleiro
 @param nl Inteiro que indica o número de colunas do tabuleiro
 @param board Matriz com as letras do tabuleiro
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */

typedef struct struct_board{
	int nc;
	int nl;
	char **board;
}*BOARD;


/**
 @brief Função que inicializa um tabuleiro
 @details Função que inicializa um tabuleiro dado as dimensões do mesmo
 @param nc Inteiro que indica o número de linhas do tabuleiro
 @param nl Inteiro que indica o número de colunas do tabuleiro
 @return Tabuleiro inicializado
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
BOARD board_init(int nl, int nc);

/**
 @brief Função que adiciona uma linha num tabuleiro
 @details Função que adiciona uma linha num tabuleiro numa linha específica
 @param row String com as letras da linha a inserir
 @param pos Inteiro que indica a linha a inserir
 @param board Tabuleiro já inicializado
 @return Tamanho da String adicionada
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int add_row(char* row,int pos,BOARD board);

/**
 @brief Função que imprime um tabuleiro
 @details Função que imprime um tabuleiro para o stdout
 @param board Tabuleiro já inicializado
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
void board_print(BOARD board);

/**
 @brief Função que carrega um tabuleiro a partir de um ficheiro
 @details Função que carrega um tabuleiro a partir de um ficheiro que contem um tabuleiro válido
 @param file String com o nome do ficheiro. O ficheiro com as dimensoes do tabuleiro e respetivo tabuleiro
 @return Tabuleiro inicializado e preenchido com os dados contidos no ficheiro
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
BOARD board_load(char file[]);
