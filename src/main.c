#include "main.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"
#include "movement.h"
#include "text.h"
#include "entityManager.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>

void cleanUp(Entity* ent, SDL_Window* window, SDL_Renderer* ren) {
    SDL_DestroyTexture(ent->texture);
    destroyEntity(ent);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    App app;

    memset(&app, 0, sizeof(App));

    initSDL(&app);

    Entity* player = buildEntity("assets/pixel_ship.png", app.renderer);


    while (1) {

        prepareScene(app.renderer);

        doInput(&app);

        //movement(&app, player->rect);

        drawText(app.renderer);
        drawToScreen(player->texture, player->rect, app.renderer);

        presentScene(app.renderer);

        SDL_Delay(16);
    }


    cleanUp(player, app.window, app.renderer);


    return 0;
}