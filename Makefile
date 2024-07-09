build:
	gcc -Wall -std=c99 -Iinclude ./src/*.c -lSDL2 -lSDL2_image -lSDL2_ttf -o game -g

run:
	./game

clean:
	rm game

debug:
	# start in tui mode i.e. view the code running not machine code
	#gdb -tui ./game
	gdb -tui ./game

	