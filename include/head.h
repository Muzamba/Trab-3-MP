/**
*@file pilha.h
*
*@brief Header que possui os cabeçalhos das funções
*
*@author Ariel Batista da Silva, matrícula 17/0099776
*
*/
// Copyright "2018" Ariel Batista
#include<iostream>
#define TRUE 1
#define FALSE 0
#define EXCEPTION -1
#define ASPAS '"'

// Assertivas

/* Se essa função receber o nome correto de um arquivo existente
e nesse arquivo não contem nenhum '"'
Então ela retornara o número de linhas relevantes
(diferente de linhas comentadas e linhas em branco) do arquivo enviado a ela.
*/
/* Essa função ao receber o nome do arquivo como parâmetro ela cria um ponteiro
e abre o arquivo. Depois ela vai pecorrendo o arquivo caractere por caractere.
Ao chegar em um caractere diferente de barra de espaço,tabe e \n ele verifica
se é um comenterio, se não for a linha ja é contabilizada  em um contador
e assim vai até o final do arquivo assim tornando a resposta correta.
*/
unsigned int contaLinhas(const char* nomeArquivo);



/* Se essa função receber um ponteiro de arquivo válido(não nulo e já aberto)
Então ela fará com que o ponteiro do arquivo se mova para o primeiro
final de comentario que encontrar ou ate o fnal do aqrquivo se não touver
final de comentario.
*/
/* Após receber o ponteiro de arquivo ela vai lendo caracter por caracter até
achar um *, depois que ela acha ela verifica se o proximo caractere depois
dele é um / se for ele ja sair da função, se não for ele continua procurando
por um *, se no meio desse processo ele tiver achado um \n ele ja salva isso
pois ira retorna 1 avisando que aconteceu uma quebra de linha caso contrário
retorna 0.
*/
int pulaComentario(FILE* pont);



/* Se essa função receber um ponteiro de arquivo válido(não nulo e já aberto)
Então ela fará com que o ponteiro de arquivo que foi recebido como parâmetro
ande até até a primeira aspas duplas que encontrar pelo caminho(").
*/
/* Após receber o ponteiro de arquivo ela vai lendo caracter por caracter até
achar um ", ao achar ele ja retorna 1 avisando que encontrou caso não ache ele
ira pecorrer o arquivo todo e retornaram -1 informando o ocorrido
*/
int pulaAspas (FILE* pont);