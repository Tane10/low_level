build:
	gcc -Wall -std=c99 -Iinclude ./src/*.c -lSDL2 -o game

run:
	./game

clean:
	rm game