build:
	gcc -Wall -std=c99 -Iinclude ./src/*.c -lSDL2 -lSDL2_image -lSDL2_ttf -o game
	
build-debug:
	gcc -Wall -std=c99 -Iinclude ./src/*.c -lSDL2 -lSDL2_image -lSDL2_ttf -o game -Og -ggdb3 -fsanitize=address

run:
	./game

clean:
	rm game

debug:
	gdb ./game

	