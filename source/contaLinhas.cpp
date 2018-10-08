// Copyright "2018" Ariel Batista
#include"../include/head.h"
unsigned int contaLinhas(const char* nomeArquivo) {
  unsigned int cont = 0;
  FILE* pont;
  char letra;
  int linhaLida = 0;
  pont = fopen(nomeArquivo , "r");
  letra = fgetc(pont);
  while (!feof(pont)) {
    if (letra != '\n') {
      if (linhaLida == 0 && letra != ' ') {
        cont++;
        linhaLida = 1;;
      }
    } else {
      linhaLida = 0;
    }
    letra = fgetc(pont);
  }
  fclose(pont);
  return cont;
}
