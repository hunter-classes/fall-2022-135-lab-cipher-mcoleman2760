#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Ciphers That Solve"){
   CHECK(solve("T hlye ez hzcv le rzzrwp zyp olj") == "I want to work at google one day");
    CHECK(solve("Xzypj lyo Xzypj") == "Money and Money");
    CHECK(solve("Krz pdqb fdvhv vkrxog L gr?") == "How many cases should I do?");
    CHECK(solve("Cn'm vyx ncgy") == "It's bed time");

}
TEST_CASE("Ciphers That Wont Solve"){
    CHECK(solve("prqhb") != "money");
    CHECK(solve("Krz pxfk orqjhu?") != "How much longer?");
    CHECK(solve("zkdw gr l gr") != "what do i do");

}
