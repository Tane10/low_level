#include "stage.h"
#include "structs.h"
#include "draw.h"
#include "defs.h"
#include "globals.h"

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_log.h>

void initStage(SDL_Renderer* ren) {

    app.delegate.logic = logic;
    app.delegate.draw = draw;

    memset(&app.stage, 0, sizeof(Stage));

    app.stage.fighterTail = &app.stage.fighterHead;
    app.stage.bulletTail = &app.stage.bulletTail;

    initPlayer(&app.stage);

    SDL_Texture* bulletTexture = loadTexture("assets/pixel_laser_red.png", ren);
}


static void initPlayer(Stage* stage, SDL_Renderer* ren) {

    Entity* player = malloc(sizeof(Entity));

    if (player == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to allocate memory to player");
        exit(1);
    }

    memset(player, 0, sizeof(Entity));

    stage->fighterTail->next = player;
    stage->fighterTail = player;

    player->x = 100;
    player->x = 100;
    player->texture = loadTexture("assets/pixel_ship.png", ren);

    if (SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h) != 0) {
        printf("Failed to get texture attrs: %s \n", SDL_GetError());
    }



}