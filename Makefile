CC=g++ -Wall --std=c++11

main: bin main.cpp Game.cpp
	$(CC) main.cpp Game.cpp -o bin/hello -lSDL2

bin:
	mkdir -p bin

clean:
	rm -rf bin