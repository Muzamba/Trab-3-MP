// Copyright "2018" Ariel Batista
#include"../include/head.h"
long int contaLinhas(const char* nomeArquivo) {
	long int cont = 0;
  FILE* pont;
  char a;
  pont = fopen(nomeArquivo,"r");
  while(1){ 
    a = fgetc(pont);
    if(feof(pont)){
      break;
    }
    if(a == '\n'){
      cont++;
    }
  }
  fclose(pont);
  return cont;
}
