// Copyright "2018" Ariel Batista
#include"../include/head.h"
unsigned int contaLinhas(const char* nomeArquivo) {
  unsigned int cont = 0;
  FILE* pont;
  char letra;
  int linhaLida = 0;  // flag que auxilia a verificação de uma linha
  pont = fopen(nomeArquivo , "r");
  letra = fgetc(pont);  // preparando o ponteiro para entrar no while
  while (!feof(pont)) {
    if (letra == '/') {
      letra = fgetc(pont);
      if (letra == '*') {
        if (pulaComentario(pont)) {
          linhaLida = 0;
        }
        letra = fgetc(pont);
      } else {
        fseek(pont, -1, 1);
      }
    }
    if (letra != '\n') {
      if (linhaLida == 0 && letra != ' ') {  // verificando se é uma linha
        if (letra == '/') {
          letra = fgetc(pont);
          if (letra == '/') {
            linhaLida = 1;
          } else {
            cont++;
            linhaLida = 1;
          }
          fseek(pont, -1, 1);  // recuando o ponteiro avançado
        } else {
          cont++;
          linhaLida = 1;
        }
      }
    } else {
      linhaLida = 0;  // zerando a flag
    }
    letra = fgetc(pont);
  }
  fclose(pont);
  return cont;
}

int pulaComentario(FILE* pont) {
  char letra;
  int flag = 0;
  while (1) {
    letra = fgetc(pont);
    if (letra == '*') {
      letra = fgetc(pont);
      if (letra == '/') {
        break;
      }
      fseek(pont, -1, 1);
    } else if (letra == '\n') {
      flag = 1;
    }
  }
  return flag;
}
