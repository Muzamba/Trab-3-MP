/**
*@file teste.cpp
*
*@brief Testes
*
*@author Ariel Batista da Silva, matrícula 17/0099776
*
*/
// Copyright "2018" Ariel Batista
#define CATCH_CONFIG_MAIN
#include"../include/head.h"
#include"../lib/catch.hpp"
TEST_CASE("Função contaLinhas", "[contaLinhas]") {
  SECTION("Arquivo vazio") {
    REQUIRE(contaLinhas("testFiles/arquivo00.txt") == 0);
  }
  SECTION("Arquivo com linhas seguidas") {
    REQUIRE(contaLinhas("testFiles/arquivo01.txt") == 10);
  }
  SECTION("Arquivo com linhas intercaladas") {
    REQUIRE(contaLinhas("testFiles/arquivo02.txt") == 10);
  }
  SECTION("Arquivo com linhas em branco com barra de espaço") {
    REQUIRE(contaLinhas("testFiles/arquivo03.txt") == 8);
  }
  SECTION("Arquivo com linhas comentadas com //") {
    REQUIRE(contaLinhas("testFiles/arquivo04.txt") == 10);
  }
  SECTION("Arquivo com linhas comentadas com /* */") {
    REQUIRE(contaLinhas("testFiles/arquivo05.txt") == 4);
  }
  SECTION("Arquivo com linhas com /* */ dentro de aspas e tab") {
    REQUIRE(contaLinhas("testFiles/arquivo06.txt") == 11);
  }
}
