

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
    REQUIRE(s.c_str() != nullptr);
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
        REQUIRE(h.c_str() != nullptr);
        REQUIRE(s == h);
    }

    SECTION("An empty string can be re-assigned to an empty string") {
        string a;
        REQUIRE(a == s);
        a = s;
        REQUIRE(a == s);
    }

    SECTION("A non-empty string can be assigned to an empty string") {
        string a = not_my_string;
        REQUIRE(a == not_my_string);
        a = s;
        REQUIRE(a == s);
    }
}

TEST_CASE("A string can be instantiated from a non-empty string") {\
    string s = my_string;
    REQUIRE(s.length() == 9);
    REQUIRE(s == my_string);
    REQUIRE(s != not_my_string);

    SECTION("A non-empty string assigned to itself") {
        s = s;
        REQUIRE(s == s);
    }

    SECTION("An empty string can be re-assinged with the assignment operator") {
        string a;
        a = s;
        REQUIRE(a.length() == s.length());
        REQUIRE(a == s);
    }

    SECTION("A non-empty string can be re-assigned with the assignment operator") {
        string a = not_my_string;
        REQUIRE(a.c_str() != not_my_string);
        REQUIRE(a == not_my_string);
        a = s;
        REQUIRE(a.length() == s.length());
        REQUIRE(a == s);
    }

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

TEST_CASE("Instantiating a string from a nullptr throws exception") {
    try {
        string s(nullptr);
        REQUIRE(false);
    } catch (std::exception& e) {
        REQUIRE(true);
    }
}