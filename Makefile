CC=g++ -Wall --std=c++11

main: bin main.cpp
	$(CC) main.cpp -o bin/hello -lSDL2

bin:
	mkdir -p bin

clean:
	rm -rf bin