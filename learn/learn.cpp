
// The function on test
int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n-1);
}

#ifdef EBUG

// A quick "environment" test
#include <cstdio>
int main() {
    printf("4! = %d\n", fact(4));
    return 0;
}
#else // EBUG not defined 

// The unit test

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"

/*unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}*/

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( fact(0) == 1);
    REQUIRE( fact(1) == 1 );
    REQUIRE( fact(2) == 2 );
    REQUIRE( fact(3) == 6 );
    REQUIRE( fact(10) == 3628800 );
}

#endif