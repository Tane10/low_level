build:
	gcc -Wall -std=c99 -Iinclude ./src/*.c -lSDL2 -lSDL2_image -o game

run:
	./game

clean:
	rm game