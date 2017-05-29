

#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include "string.h"
#include <cstdio>

const char my_string[] = "My string";
const char not_my_string[] = "My strinf";

TEST_CASE("An empty string can be instantiated.") {
    puts("test_case: empty string");
    string s;
    REQUIRE(s.length() == 0);
    REQUIRE(s == "");
    REQUIRE(s != my_string);

    SECTION("Strings can have data appended to them") {
        puts("test_case: empty append");
        s.append("nothing");
        REQUIRE(s.length() == 7);
        REQUIRE(s == "nothing");
    }
}

TEST_CASE("A string can be instantiated from a string literal") {
    puts("test_case: non-empty string");
    string s = my_string;
    REQUIRE(s.length() == 9);
    REQUIRE(s == my_string);
    REQUIRE(s != not_my_string);

    SECTION("Data can be appended to non-empty strings.") {
        puts("test_case: non-empty append");
        s.append(not_my_string);
        REQUIRE(s.length() == 18);
        REQUIRE(s == "My stringMy strinf");
    }
}