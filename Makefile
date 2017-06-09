string: src/string/*
	g++ src/string/string_test.cpp src/string/string.cpp --std=c++11 -o bin/string_test
	./bin/string_test

vector: src/vector/*
	g++ src/vector/vector_test.cpp src/vector/vector.cpp --std=c++11 -o bin/vector_test
	./bin/vector_test

learn: learn/learn.cpp
	g++ learn/learn.cpp --std=c++11 -o bin/learn
	./bin/learn

clean:
	rm bin/*.exe