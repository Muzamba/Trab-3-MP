// Copyright "2018" Ariel Batista
#define CATCH_CONFIG_MAIN
#include"../include/head.h"
#include"../lib/catch.hpp"
TEST_CASE("Função contaLinhas", "[contaLinhas]") {
  SECTION("Arquivo vazio") {
    REQUIRE(contaLinhas("testFiles/arquivo00.txt") == 0 );
  }
    SECTION("Arquivo com linhas seguida") {
    REQUIRE(contaLinhas("testFiles/arquivo01.txt") == 10 );
  }
}
