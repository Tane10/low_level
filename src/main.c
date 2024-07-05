#include "main.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"
#include "movement.h"
#include "text.h"
#include "defs.h"
#include "globals.h"


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

void static logic(void) {}


int main(int argc, char* argv[]) {

    Entity player;
    Entity bullet;

    SDL_Rect rect;
    SDL_Rect rectB;

    //TODO: Clean up this entity stuff 

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

    memset(&bullet, 0, sizeof(Entity));
    bullet.rect = &rectB;
    bullet.texture = loadTexture("assets/pixel_laser_red.png", app.renderer);


    while (1) {

        prepareScene(app.renderer);
        drawText(app.renderer);

        doInput(&app, &player);

        player.rect->x += player.dx;
        player.rect->y += player.dy;

        movement(&app, player.rect, &(player.speed));


        if (app.fire && bullet.health == 0) {
            bullet.rect->x = player.rect->x;
            bullet.rect->y = player.rect->y;
            bullet.dx = 16;
            bullet.dy = 0;
            bullet.health = 1;
        }

        bullet.rect->x += bullet.dx;
        bullet.rect->y += bullet.dy;


        if (bullet.rect->x > SCREEN_WIDTH) {
            bullet.health = 0;
        }


        drawToScreen(player.texture, player.rect, app.renderer);


        if (bullet.health > 0) {
            drawToScreen(bullet.texture, bullet.rect, app.renderer);
        }


        presentScene(app.renderer);

        SDL_Delay(16);
    }


    cleanUp(&player, app.window, app.renderer);
    free(&bullet);


    return 0;
}