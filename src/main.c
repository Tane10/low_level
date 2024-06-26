#include <stdio.h>
#include <SDL2/SDL.h>
#include <structs.h>
#include "defs.h"


int main(int argc, char* argv[]) {
	memset(&app, 0, sizeof(App));

	initSDL();

	// atexit(cleanup);

	while (1) {
		prepareScene();

		doInput();

		presentScene();

		SDL_Delay(16);
	}
	// printf("this is the main");/
	return 0;
}