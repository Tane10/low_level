#include "main.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"
#include "movement.h"
#include "text.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>

void cleanUp(Entity* ent, SDL_Window* window, SDL_Renderer* ren) {
    SDL_DestroyTexture(ent->texture);
    free(ent);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    App app;
    Entity player;
    SDL_Rect rect;

    memset(&app, 0, sizeof(App));

    initSDL(&app);

    // init player
    memset(&player, 0, sizeof(Entity));
    player.rect = &rect;
    player.rect->x = 100;
    player.rect->y = 100;
    player.rect->w = 50;
    player.rect->h = 50;
    player.speed = 4;

    player.texture = loadTexture("assets/pixel_ship.png", app.renderer);


    while (1) {

        prepareScene(app.renderer);

        doInput(&app, &player);

        movement(&app, player.rect, &(player.speed));

        drawText(app.renderer);
        drawToScreen(player.texture, player.rect, app.renderer);

        presentScene(app.renderer);

        SDL_Delay(16);
    }


    cleanUp(&player, app.window, app.renderer);


    return 0;
}