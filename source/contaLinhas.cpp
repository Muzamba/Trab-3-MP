// Copyright "2018" Ariel Batista
#include"../include/head.h"
unsigned long int contaLinhas(const char* nomeArquivo) {
  unsigned long int cont = 0;
  FILE* pont;
  char letra;
  short int linhaLida = 0;
  pont = fopen(nomeArquivo , "r");
  letra = fgetc(pont);
  while (!feof(pont)) {
    //letra = fgetc(pont);
    //if (feof(pont)) {
    //  break;
    //}
    if (letra != '\n') {
      if(linhaLida == 0) {
        cont++;
        linhaLida = 1;;
      }
    }else {
      linhaLida = 0;
    }
    letra = fgetc(pont);
  }
  fclose(pont);
  return cont;
}
