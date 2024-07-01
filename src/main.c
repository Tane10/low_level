#include <stdio.h>
#include <SDL2/SDL.h>

#include "structs.h"
#include "defs.h"
#include "init.h"
#include "draw.h"
#include "input.h"


int main(int argc, char* argv[]) {

	App app;
	memset(&app, 0, sizeof(App));

	initSDL(&app);

	// atexit(cleanup);

	while (1) {
		prepareScene(&app);

		doInput();

		presentScene(&app);

		SDL_Delay(16);
	}
	// printf("this is the main");/

	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
	return 0;
}