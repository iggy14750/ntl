

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "string.h"
#include <cstdio>
using namespace ntl;

const char my_string[] = "My string";
const char not_my_string[] = "My strinf";

TEST_CASE("An empty string can be instantiated.") {
    string s;
    REQUIRE(s.length() == 0);
    REQUIRE(s.c_str() == (char*)NULL);
    REQUIRE(s == "");
    REQUIRE(s != my_string);

    SECTION("Strings can have data appended to them") {
        s.append("nothing");
        REQUIRE(s.length() == 7);
        REQUIRE(s == "nothing");
    }

    SECTION("A string copy-constructed from an empty string") {
        string h(s);
        REQUIRE(h.length() == 0);
        REQUIRE(h.c_str() == (char*)NULL);
        REQUIRE(s == h);
    }
}

TEST_CASE("A string can be instantiated from a non-empty string") {\
    string s = my_string;
    REQUIRE(s.length() == 9);
    REQUIRE(s == my_string);
    REQUIRE(s != not_my_string);

    SECTION("Data can be appended to non-empty strings.") {
        s.append(not_my_string);
        REQUIRE(s.length() == 18);
        REQUIRE(s == "My stringMy strinf");
    }

    SECTION("A string copy-constructed from non-empty string") {
        string h(s);
        REQUIRE(h.length() == s.length());
        REQUIRE(h == s);
        REQUIRE(h == my_string);
        REQUIRE(h != not_my_string);
    }
}