#!usr/bin/python

# A little script which sets up a new project space when I need it.
# This is purpose-built for this project.
# USE: `python mkmod.py <name> [mf]`

# This sets up a new directory with the following structure:
# <name>/
#   Makefile
#   bin/
#   src/
#       <name>.cpp
#       <name>.h
#       test.cpp
#       debug.cpp

# such that the Makefile will by default have a recipe with
# the same name as the directory (as the first recipe) which
# will compile and run the test. This compilation will be done
# incrementally, one big feature of C++. The Makefile will also
# contain a recipe for building `debug` which will have an
# alternative main used for debugging specific pieces of code.
# Note that this Makefile will also run the built executable.
# If the optional command-line argument `[mf]` is given,
# then only the Makefile will be constructed in the current directory

# Further, the source files will be instantiated with what I
# consider to be a sensible default body.



TEST_TEMPLATE = """
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "{name}.h"
"""

HEADER_TEMPLATE = """
class {name} {{

}};
"""

IMPL_TEMPLATE = """
#include {name}.h
"""

DEBUG_TEMPLATE = """
#include "{name}.h"

int main() {{
    
    return 0;
}}
"""

SRC_TEMPLATES = (
    ("test.cpp",   TEST_TEMPLATE),
    ("debug.cpp",  DEBUG_TEMPLATE),
    ("{name}.cpp", IMPL_TEMPLATE),
    ("{name}.h",   HEADER_TEMPLATE)
)

MAKEFILE_TEMPLATE = """
# run the final binary
{name}: bin/{name}.exe
\t./bin/{name}

debug: bin/debug.exe
\t./bin/debug

# link object files
bin/{name}.exe: bin/{name}.o bin/test.o
\tg++ bin/{name}.o bin/test.o -o bin/{name}.exe

bin/debug.exe: bin/debug.o bin/{name}.o
\tg++ bin/debug.o bin/{name}.o -o bin/debug.exe

# compile {name}.cpp to an object file
bin/{name}.o: src/{name}.cpp src/{name}.h
\tg++ -c -g src/{name}.cpp -o bin/{name}.o

bin/test.o: src/test.cpp src/{name}.h
\tg++ -c src/test.cpp -o bin/test.o

bin/debug.o: src/debug.cpp src/{name}.h
\tg++ -c -g src/debug.cpp -o bin/debug.o

clean:
\trm bin/*
"""

import sys
import os

def main():
    proj_name = sys.argv[1]
    if mf_only():
        make_makefile(proj_name)
        exit()

    os.mkdir(proj_name)      # create base directory
    os.chdir(proj_name)      # move into that directory
    make_makefile(proj_name) # create Makefile in place
    os.mkdir("bin")          # create a dir for binaries
    os.mkdir("src")          # create a dir for source files
    os.chdir("src")          # move into this dir.

    for title, body in SRC_TEMPLATES:
        t = title.format(name = proj_name)
        with open(t, "w") as f:
            content = body.format(name = proj_name)
            f.write(content)


def make_makefile(name):
    with open("Makefile", "w") as mf:
        mf.write(MAKEFILE_TEMPLATE.format(name = name))

def mf_only():
    return len(sys.argv) > 2 and sys.argv[2] == "mf"


if __name__ == '__main__':
    main()
