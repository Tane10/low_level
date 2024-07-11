build:
	gcc -Wall -std=c99 -Iinclude ./src/*.c -lSDL2 -lSDL2_image -lSDL2_ttf -o game

build-mac:
	gcc -Wall -std=c99 -Iinclude -I/opt/homebrew/include -L/opt/homebrew/lib ./src/*.c -lSDL2 -lSDL2_image -lSDL2_ttf -o game -g

debug-mac:
	gcc -Wall -std=c99 -Iinclude -I/opt/homebrew/include -L/opt/homebrew/lib ./src/*.c -lSDL2 -lSDL2_image -lSDL2_ttf -o game  -Og -ggdb3 -fsanitize=address∆∆
	
build-debug:
	gcc -Wall -std=c99 -Iinclude ./src/*.c -lSDL2 -lSDL2_image -lSDL2_ttf -o game -Og -ggdb3 -fsanitize=address

run:
	./game

clean:
	rm game

debug:
	gdb ./game
