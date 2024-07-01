#include <stdio.h>
#include <SDL2/SDL.h>

#include "structs.h"
#include "defs.h"
#include "init.h"
#include "draw.h"
#include "input.h"


int main(int argc, char* argv[]) {

	App app;
	Entity player;


	memset(&app, 0, sizeof(App));
	memset(&player, 0, sizeof(Entity));

	initSDL(&app);

	player.x = 100;
	player.y = 100;
	player.texture = loadTexture("src/assest/spacepixels-0.2.0/pixel_ship_blue.png", &app);

	// atexit(cleanup);

	while (1) {
		prepareScene(&app);

		doInput();

		blit(player.texture, player.x, player.y, &app);

		presentScene(&app);

		SDL_Delay(16);
	}
	// printf("this is the main");/

	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	SDL_Quit();
	return 0;
}