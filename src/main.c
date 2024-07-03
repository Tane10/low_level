#include "main.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"
#include "movement.h"

#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    App app;
    Entity player;
    SDL_Rect rect;

    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));

    initSDL(&app);

    player.rect = &rect;
    player.rect->x = 100;
    player.rect->y = 100;
    player.rect->w = 50;
    player.rect->h = 50;

    player.texture = loadTexture("assets/pixel_ship.png", app.renderer);

    if (!player.texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load texture");
        return 1;
    }


    while (1) {

        prepareScene(app.renderer);

        doInput(&app);

        movement(&app, player.rect);

        drawToScreen(player.texture, player.rect, app.renderer);

        presentScene(app.renderer);

        SDL_Delay(16);
    }

    free(&player);

    return 0;
}