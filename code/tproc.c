#include <stdio.h>
#include "stdlib.h"
#include "cadeias.h"

int main() {
	char* s1 = "ola";
	char* s2 = (char*) malloc(sizeof(char)*cad_tamanho(s1)*2);

	printf("1: %d\n", cad_tamanho(""));
	printf("2: %d\n", cad_procurar_car('b',"abaco"));
	printf("3: %d\n", cad_procurar_car('z',"abaco"));
	printf("4: %d\n", cad_ocorrencias('a',"abaco"));
	printf("5: %d\n", cad_procurar_str("abc","a"));
	printf("6: %d\n", cad_procurar_str("abc","abaco"));
	printf("7: %d\n", cad_procurar_str("abc","olaabcd"));
	printf("8: %d\n", cad_e_prefixo("abc","olaabcd"));
	printf("9: %d\n", cad_e_prefixo("abc","olaabcd"));
	printf("10: %d\n", cad_e_prefixo("abc","abcdefg"));
	printf("11: %d\n", cad_e_prefixo("abc","ab"));
	printf("12: %d\n", cad_e_sufixo("abc","ab"));
	printf("13: %d\n", cad_e_sufixo("ab","abc"));
	printf("14: %d\n", cad_e_sufixo("abc","cabc"));
	printf("15: %d\n", cad_iguais("abc","abc"));
	printf("16: %d\n", cad_iguais("abc","acb"));
	printf("16: %d\n", cad_primeiro("abc","abc"));
	printf("17: %d\n", cad_primeiro("abc","abcde"));
	printf("18: %d\n", cad_primeiro("abcde","abc"));
	printf("19: %d\n", cad_comparar("abc","abc"));
	printf("20: %d\n", cad_comparar("abc","abcde"));
	printf("21: %d\n", cad_comparar("abcde","abc"));
	printf("22: %d\n", cad_um_dos("abcde","gtb"));
	printf("23: %d\n", cad_um_dos("abc","def"));
	printf("24: %d\n", cad_nenhum_dos("abcde","gtb"));
	printf("25: %d\n", cad_nenhum_dos("abc","adebf"));

	cad_copiar(s1,s2);
	printf("26: %s\n", s2);

	cad_colar(s1,s2);
	printf("27: %s\n", s2);

	cad_mover(s2+1,s2,4);
	printf("28: %s\n", s2);


	return 0;
}
