
# run the final binary
vector: bin/vector.exe
	./bin/vector

debug: bin/debug.exe
	./bin/debug

# link object files
bin/vector.exe: bin/vector.o bin/test.o
	g++ bin/vector.o bin/test.o -o bin/vector.exe

bin/debug.exe: bin/debug.o bin/vector.o
	g++ bin/debug.o bin/vector.o -o bin/debug.exe

# compile vector.cpp to an object file
bin/vector.o: src/vector.cpp src/vector.h
	g++ -c src/vector.cpp -o bin/vector.o

bin/test.o: src/test.cpp src/vector.h
	g++ -c src/test.cpp -o bin/test.o

bin/debug.o: src/debug.cpp src/vector.h
	g++ -c src/debug.cpp -o bin/debug.o

clean:
	rm bin/*
