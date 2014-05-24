#include "cadeias.h"

int cad_tamanho(char s[]){
	if (s[0] == '\0')
		return 0;
	else
		return 1 + cad_tamanho(s+1);
}

int cad_procurar_car(char c, char s[]){
	int len = cad_tamanho(s);
	int encontrou = 0;
	int res = -1;
	int i;

	for ( i = 0; i < len && !encontrou; ++i){
		if(s[i] == c){
			res = i;
		}
	}

	return res;
}

int cad_ocorrencias(char c, char s[]){
	int len = cad_tamanho(s);
	int res = 0;
	int i;

	for ( i = 0; i < len; ++i){
		if(s[i] == c)
			res++;
	}

	return res;
}

int cad_procurar_str(char s1[], char s2[]){
	int len1 = cad_tamanho(s1);
	int len2 = cad_tamanho(s2);
	int i,j=0;
	int restantes = len1;

	for (i = 0; i < len2 && restantes;i++){
		if(s1[j] == s2[i]){
			restantes--;
			j++;
		}
		else{
			i=i-j;
			j=0;
			restantes=len1;
		}
	}
	if(restantes)
		return -1;
	return i-j;
}

int cad_e_prefixo(char s1[], char s2[]){
	int len1 = cad_tamanho(s1);
	int len2 = cad_tamanho(s2);
	int i,flag;

	if(len1 > len2)
		return 0;

	for(i = 0,flag=1;flag && i < len1;i++){
		if(s1[i] != s2[i])
			flag=0;
	}

	return flag;
}

int cad_e_sufixo(char s1[], char s2[]){
	int len1 = cad_tamanho(s1);
	int len2 = cad_tamanho(s2);
	int i,j,flag;

	if(len1 > len2)
		return 0;


	for(i = 0,j = len2-len1,flag=1;flag && i < len1;i++,j++){
		if(s1[i] != s2[j])
			flag=0;
	}

	return flag;
}

int cad_iguais(char s1[], char s2[]){
	int len1 = cad_tamanho(s1);
	int len2 = cad_tamanho(s2);
	int i,flag;

	if(len1 != len2)
		return 0;


	for(i = 0,flag=1;flag && i < len1;i++){
		if(s1[i] != s2[i])
			flag=0;
	}

	return flag;
}

int cad_primeiro(char s1[], char s2[]){
	int len1 = cad_tamanho(s1);
	int len2 = cad_tamanho(s2);
	int i,flag;

	if(cad_iguais(s1,s2))
		return 0;

	for(i = 0,flag=1;flag && i < len1 && i< len2;i++){
		if(s1[i] > s2[i])
			flag=0;
	}

	if(flag){
		flag=len1<len2?1:0;
	}

	return flag;
}

int cad_comparar(char s1[], char s2[]){
	int len1 = cad_tamanho(s1);
	int len2 = cad_tamanho(s2);
	int res = 0;
	int i;

	for(i = 0; i<len1 && i<len2 && !res; i++){
		if(s1[i]<s2[i])
			res--;
		else if(s1[i]>s2[i])
			res++;
	}

	if(!res){
		if(len1<len2)
			res--;
		else if(len1>len2)
			res++;
	}

	return res;
}

int cad_um_dos(char s1[], char s2[]){
	int len1 = cad_tamanho(s1);
	int flag = 1;
	int i;

	for(i = 0; i<len1 && flag; i++){
		if(cad_ocorrencias(s1[i],s2))
			flag--;
	}

	if(!flag)
		return i-1;
	return -1;
}

int cad_nenhum_dos(char s1[], char s2[]){
	int len1 = cad_tamanho(s1);
	int flag = 1;
	int i;

	for(i = 0; i<len1 && flag; i++){
		if(!cad_ocorrencias(s1[i],s2))
			flag--;
	}

	if(!flag)
		return i-1;
	return -1;
}

int cad_copiar(char s1[], char s2[]){
	while ((*s2++ = *s1++));
	return 1;
}

int cad_colar(char s1[], char s2[]){
	int len = cad_tamanho(s1);
	int i,j;

	for ( i = 0, j = len; i <= len; ++i, j++){
		s2[j] = s1[i];
	}
	return i;
}

int cad_mover(char m1[], char m2[], int n){
	while (n-- && (*m2++ = *m1++));
	return 1;
}

