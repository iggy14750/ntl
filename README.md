
Nonstandard Template Library (NTL)
==================================

This is a little toy project for me to expiriment with TDD, and C++.
Using [Catch](https://github.com/philsquared/Catch) as the testing framework, I plan to implement a subset of the C++ [Standard Template Library](https://en.wikipedia.org/wiki/Standard_Template_Library).
This will include data structures such as `vector`, `string`, `map`, `list`, algorithms such as `sort`, and others.
This is a pet project, again, to get hands-on with TDD, C++, and all the stuff I forgot from CS 1501.
It's not unlikely that I will add other containers and algorithms not found in the STL, such as red-black trees, and a generic `graph` container, along with a few standard algorithms on it.
Also note that I plan to do this in a C++11 (maybe even 17) style, including smart pointers, range-for, lambdas, etc, where appropriate.

**Also note** that I plan to include all tests so that others can validate my work.
To that end, I will be including the *Catch* test suite, which is bundled up in a single header file.
Thus, my use of `catch.h` is not meant to imply that it is my own work. Follow the link above to the real author.
Many thanks for his development and release of such a tool.