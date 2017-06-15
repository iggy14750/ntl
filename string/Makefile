
# run the final binary
string: bin/string.exe
	./bin/string

debug: bin/debug.exe
	./bin/debug

# link object files
bin/string.exe: bin/string.o bin/test.o
	g++ bin/string.o bin/test.o -o bin/string.exe

bin/debug.exe: bin/debug.o bin/string.o
	g++ bin/debug.o bin/string.o -o bin/debug.exe

# compile string.cpp to an object file
bin/string.o: src/string.cpp src/string.h
	g++ -c src/string.cpp -o bin/string.o

bin/test.o: src/test.cpp src/string.h
	g++ -c src/test.cpp -o bin/test.o

bin/debug.o: src/debug.cpp src/string.h
	g++ -c src/debug.cpp -o bin/debug.o

clean:
	rm bin/*
