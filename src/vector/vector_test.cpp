

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "vector.h"


TEST_CASE("Instantiate a vector") {

    SECTION("With no parameters") {
        vector v;
        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() == 8);
    }

    SECTION("With default capacity") {
        vector v(10);
        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() == 10);
    }
}