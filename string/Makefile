
# run the final binary
string: bin/string.exe
	./bin/string

debug: bin/debug.exe
	./bin/debug

# link object files
bin/string.exe: bin/string.o bin/test.o
	g++ bin/string.o bin/test.o -o bin/string.exe

bin/debug.exe: src/debug.cpp src/string.cpp
	g++ -g -Wall --std=c++11 src/debug.cpp src/string.cpp -o bin/debug.exe

# compile string.cpp to an object file
bin/string.o: src/string.cpp src/string.h
	g++ -c --std=c++11 src/string.cpp -o bin/string.o

bin/test.o: src/test.cpp src/string.h
	g++ -c --std=c++11 src/test.cpp -o bin/test.o

bin/debug.o: src/debug.cpp src/string.h
	g++ -c --std=c++11 src/debug.cpp -o bin/debug.o

clean:
	rm bin/*
