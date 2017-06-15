
Nonstandard Template Library (NTL)
==================================

This is a little toy project for me to expiriment with TDD, and C++.
Using [Catch](https://github.com/philsquared/Catch) as the testing framework, I plan to implement a subset of the C++ [Standard Template Library](https://en.wikipedia.org/wiki/Standard_Template_Library).
This will include data structures such as `vector`, `string`, `map`, `list`, algorithms such as `sort`, and others.
This is a pet project, again, to get hands-on with TDD, C++, and all the stuff I forgot from CS 1501.
It's not unlikely that I will add other containers and algorithms not found in the STL, such as red-black trees, and a generic `graph` container, along with a few standard algorithms on it.
Also note that I plan to do this in a C++11 (maybe even 17) style, including smart pointers, range-for, lambdas, etc, where appropriate.

**Also note** that I plan to include all tests so that others can validate my work.
I have decided to not include the *Catch* unit testing framework as was my initial plan.
It is a very large header file, and I would perfer to have one copy on disk.
This is the `catch.hpp` which is included in "test" files.
Thus, I have included it in my own include path, and in order to operate the tests yourself I recommend the reader do the same.
Please follow the link above to aquire it for yourself.
Many thanks to `philsquared` and his development and release of such a tool.