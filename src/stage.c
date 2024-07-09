#include "stage.h"
#include "structs.h"
#include "draw.h"
#include "defs.h"
#include "globals.h"
#include "movement.h"

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_log.h>

static Entity player;

void fireBullets(void) {
    Entity* bullet;
    SDL_Rect rect;
    bullet = malloc(sizeof(Entity));

    memset(bullet, 0, sizeof(Entity));

    stage.bulletTail->next = bullet;
    stage.bulletTail = bullet;

    bullet->rect = &rect;
    bullet->rect->x = player.rect->x;
    bullet->rect->y = player.rect->y;
    bullet->dx = PLAYER_BULLET_SPEED;
    bullet->health = 1;

    bullet->texture = bulletTexture;


    if (SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->rect->w, &bullet->rect->h) != 0) {
        printf("Failed to get texture attrs: %s \n", SDL_GetError());
    }

    bullet->rect->y += (player.rect->h / 2) - (bullet->rect->h / 2);
}

static void doBullets() {
    Entity* b, * prev;

    prev = &stage.bulletHead;

    for (b = stage.bulletHead.next; b != NULL; b = b->next) {
        b->rect->x += b->dx;
        b->rect->y += b->dy;

        if (b->rect->x > SCREEN_WIDTH) {
            if (b == stage.bulletTail) {
                stage.bulletTail = prev;

            }

            prev->next = b->next;
            free(b);
            b = prev;
        }

        prev = b;
    }

}

// Player setter
Entity* initPlayer(Stage* stage, SDL_Renderer* ren) {
    Entity* player = malloc(sizeof(Entity));
    SDL_Rect rect;

    if (player == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to allocate memory to player");
        exit(1);
    }

    memset(player, 0, sizeof(Entity));

    // set 1st node in linked list to be player
    stage->fighterTail->next = player;
    stage->fighterTail = player;

    // Set inital player values including texture
    player->rect = &rect;
    player->rect->y = 100;
    player->rect->x = 100;
    player->rect->w = 50;
    player->rect->h = 50;

    player->texture = loadTexture("assets/pixel_ship_blue.png", ren);  // can't find it


    if (SDL_QueryTexture(player->texture, NULL, NULL, &player->rect->w, &player->rect->h) != 0) {
        printf("Failed to get texture for player initPlayer: %s \n", SDL_GetError());
    }

    return player;
}


// Player getter
Entity* getPlayer(void) {
    return &player;
}

static void doPlayer(void) {
    movementHandler();
}


// this is failing as players texture is a null address and hasn't been set
// need to init player before we try to draw
static void drawPlayer(void) {
    Entity* player = getPlayer();
    drawToScreen(player->texture, player->rect, app.renderer);
}

static void drawBullets(void) {
    Entity* b;
    for (b = stage.bulletHead.next; b != NULL; b = b->next) {
        drawToScreen(bulletTexture, b->rect, app.renderer);
    }

}

static void draw(void) {
    drawPlayer();
    drawBullets();
}


static void logic() {
    doPlayer();
    doBullets();
}


// this is failing 
void initStage(SDL_Renderer* ren) {
    // app.delegate.logic = logic;
    // app.delegate.draw = draw;

    memset(&stage, 0, sizeof(Stage));

    stage.fighterTail = &stage.fighterHead;
    stage.bulletTail = stage.bulletTail;

    initPlayer(&stage, ren);

    app.delegate.logic = logic;
    app.delegate.draw = draw;
    // bulletTexture = loadTexture("assets/pixel_laser_red.png", ren);
}
