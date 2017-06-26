

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "string.h"
#include <cstdio>
using namespace ntl;

const char my_string[] = "My string";
const char not_my_string[] = "My strinf";

#define REQUIRE_THROW(statement) {\
try{\
    statement;\
    REQUIRE(false);\
} catch (std::exception& e) {\
    REQUIRE(true);\
}}

TEST_CASE("An empty string can be instantiated.") {
    string s;
    REQUIRE(s.length() == 0);
    REQUIRE(s.c_str() != nullptr);
    REQUIRE(s == "");
    REQUIRE(s != my_string);

    SECTION("Instantiating a string from nullptr throws") {
        REQUIRE_THROW(string s(nullptr));
    }

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

TEST_CASE("A string can be subscripted") {
    string s(my_string);

    SECTION("A string can be accessed by operator[]") {
        REQUIRE(s[0] == 'M');
        REQUIRE(s[9] == '\0');
        REQUIRE_THROW(s[10]);
    }

    SECTION("A character can be modified from a subscript") {
        s[8] = 'f';
        REQUIRE(s == not_my_string);
    }

    SECTION("A const string can be subscipted safely") {
        const string x(my_string);
        const char& c = x[0];
    }

}

TEST_CASE("A string can be instantiated with default capacity") {
    string s(8);
    REQUIRE(s.capacity() == 8);
}

TEST_CASE("Two strings can be connected into one with operator+") {
    string a(my_string);
    string b(not_my_string);

    SECTION("a + b returns the text of a followed by that of b") {
        string s = a + b;
        a.append(b);
        REQUIRE(s == a);
        REQUIRE(s == "My stringMy strinf");
    }
}