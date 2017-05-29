

#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include "string.h"

TEST_CASE("An empty string can be instantiated.") {
    string s;
    REQUIRE(s.length() == 0);
    REQUIRE(s == "");
    REQUIRE(s != "My string");
}

TEST_CASE("A string can be instantiated from a string literal") {
    string s = "My string";
    REQUIRE(s.length() == 9);
    REQUIRE(s == "My string");
    REQUIRE(s != "My strinf");
}