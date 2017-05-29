

#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include "string.h"

const char my_string[] = "My string";
const char not_my_string[] = "My strinf";

TEST_CASE("An empty string can be instantiated.") {
    string s;
    REQUIRE(s.length() == 0);
    REQUIRE(s == "");
    REQUIRE(s != my_string);

    /*SECTION("Strings can have data appended to them") {
        s.append("nothing");
        REQUIRE(s.length() == 7);
        REQUIRE(s == "nothing");
    }*/
}

TEST_CASE("A string can be instantiated from a string literal") {
    string s = my_string;
    REQUIRE(s.length() == 9);
    REQUIRE(s == my_string);
    REQUIRE(s != not_my_string);
}