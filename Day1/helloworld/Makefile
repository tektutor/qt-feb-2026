all: hello.o main.o
	g++ bin/hello.o bin/main.o -o bin/hello

hello.o: src/hello.cpp
	g++ -c src/hello.cpp -o bin/hello.o

main.o: src/main.cpp
	g++ -c src/main.cpp -o bin/main.o

clean:
	rm -f bin/*.o bin/hello
