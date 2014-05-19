#include <stdio.h>
#include "cadeias.h"

int main() {
	printf("%d\n", cad_tamanho(""));
	printf("%d\n", cad_procurar_car('b',"abaco"));
	printf("%d\n", cad_procurar_car('z',"abaco"));
	printf("%d\n", cad_ocorrencias('a',"abaco"));
	printf("%d\n", cad_procurar_str("abc","a"));
	printf("%d\n", cad_procurar_str("abc","abaco"));
	printf("%d\n", cad_procurar_str("abc","olaabcd"));


	return 0;
}
