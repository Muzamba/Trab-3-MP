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
}
