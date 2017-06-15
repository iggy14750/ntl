
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

###That Python Script
What I have included is a tool to automate the process of creating new submodules in the project.
Its operation is described in the file itself in its comments.
The reason I have created such a thing, though, is the purpose of this section.

I am expirimenting somewhat with how I want this project to work.
I have moved from one `src` directory which contains many "submodules" to an inversion: there are now many top-level submodules each with their own `src`,`bin` directories, `Makefile`s.
I get two advantages this way.

1. It is clearer from the top level what I am working on. It feels oddly "buried" to stuff all of the actual code behind a `src` folder. While I am still planning to do this, this structure makes the scope of the project more clear.  Additionally, because of the nature of the project, I believe that each individual data structure needs to be considered on its own. For this reason, I am calling this level a "submodule" to reflect its partial independence from the whole of the project.
2. I get to use local `make` recipes, which in effect allows me to use polymorphism on them. That is, `make` always compiles and runs tests, `make debug` always compiles and runs the local debug file (I might chage this to open `gdb` with the debug exe), and `make clean` always removes all binary files, but only from the local submodule.

So, while I like this orginization, it now becomes somewhat annoying to manually create the directory structure, create the files which all submodules will share, and especially write the Makefile for each submodule.
When I notice repetitive behavior, I like to automate it.
So I did.

I might at some point consider collapsing this structure so that there are no `src` and `bin` directories.