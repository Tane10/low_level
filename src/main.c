#include "main.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"

#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    App app;
    Entity player;


    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));

    initSDL(&app);

    player.x = 100;
    player.y = 100;
    player.texture = loadTexture("../src/assest/spacepixels-0.2.0/background-black.png", app.renderer);


    while (1) {
        prepareScene(&app);

        doInput();

        drawToScreen(player.texture, player.x, player.y, app.renderer);

        presentScene(&app);

        SDL_Delay(16);


    }

    return 0;

}

