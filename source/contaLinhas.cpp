// Copyright "2018" Ariel Batista
#include"../include/head.h"
/* A função contalinhas  

*/
unsigned int contaLinhas(const char* NomeArquivo) {
  unsigned int cont = 0;
  FILE* pont;
  char letra;
  int linhaLida = FALSE;  // flag que auxilia a verificação de uma linha
  int flag;
  pont = fopen(NomeArquivo , "r");
  letra = fgetc(pont);  // preparando o ponteiro para entrar no while
  while (!feof(pont)) {    // para o laço no final do arquivo
    if (letra == '/') {
      letra = fgetc(pont);
      if (letra == '*') {  // confirmando se é um /*
        if (flag = pulaComentario(pont)) {
          linhaLida = FALSE;
          if (flag == EXCEPTION) {  // se caso não exista */
            break;
          }
        }
        letra = fgetc(pont);
      } else {
        fseek(pont, -1, 1);  // recuando o ponteiro avançado anteriormente
      }
    }
    if (letra != '\n') {
      if (letra == ASPAS) {
        pulaAspas(pont);
        letra = fgetc(pont);
      }
      if (linhaLida == FALSE && letra != ' ' && letra != '\t') {
        if (letra == '/') {
          letra = fgetc(pont);
          if (letra == '/') {
            linhaLida = TRUE;
          } else {
            cont++;
            linhaLida = TRUE;
          }
          fseek(pont, -1, 1);  // recuando o ponteiro avançado anteriormente
        } else {
          cont++;
          linhaLida = TRUE;
        }
      }
    } else {
      linhaLida = FALSE;  // zerando a flag
    }
    letra = fgetc(pont);  // lendo o arquivo letra a letra
  }
  fclose(pont);
  pont = NULL;
  return cont;
}
int pulaComentario(FILE* pont) {
  char letra;
  int flag = FALSE;
  while (1) {
    letra = fgetc(pont);  // lendo letra a letra 
    if (feof(pont)) {
      return EXCEPTION;
    }
    if (letra == '*') {  // verificando se é o final do do comentario
      letra = fgetc(pont);
      if (letra == '/') {
        break;
      }
      fseek(pont, -1, 1);
    } else if (letra == '\n') {
      flag = TRUE;
    }
  }
  return flag;
}
int pulaAspas (FILE* pont) {
  char letra;
  letra = fgetc(pont);
  while (1) {
    letra = fgetc(pont);  //ledo letra a letra
    if (feof(pont)) {
      return EXCEPTION;
    }
    if (letra == ASPAS) {
      fseek(pont, -1, 1);
      return TRUE;
    }
  }
 }
