#include "globals.h"
#include "stage.h"
#include "movement.h"
#include "structs.h"

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_scancode.h>

CollisionMap* hasCollidedWithBorder(SDL_Window* window, SDL_Rect* entityRect) {
    int windowW, windowH;

    // dynamically alloted object so we can pass local var as a pointer
    CollisionMap* hitbox = malloc(sizeof(CollisionMap));

    if (hitbox != NULL) {
        hitbox->left = 0;
        hitbox->right = 0;
        hitbox->top = 0;
        hitbox->bottom = 0;
    }

    SDL_GetWindowSize(window, &windowW, &windowH);

    if (entityRect->x <= 0) {
        hitbox->left = 1;
        //SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Hit left wall");
    }

    if (entityRect->y <= 0) {
        hitbox->top = 1;
        // SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Hit top wall");
    }

    if (entityRect->x + entityRect->w >= windowW) {
        hitbox->right = 1;
        // SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Hit right wall");
    }

    if (entityRect->y + entityRect->h >= windowH) {
        hitbox->bottom = 1;

        // SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Hit bottom wall");
    }

    return hitbox;
}


void movementHandler(void) {
    Entity* player = getPlayer();

    // add in later
    // CollisionMap* collided = hasCollidedWithBorder(app.window, player->rect);

    if (app.keyboard[SDL_SCANCODE_UP]) {
        // if (!collided->top) {
        player->rect->y -= PLAYER_SPEED;
        // }
    }

    if (app.keyboard[SDL_SCANCODE_DOWN]) {
        // if (!collided->bottom) {
        player->rect->y += PLAYER_SPEED;
        // }
    }

    if (app.keyboard[SDL_SCANCODE_RIGHT]) {
        // if (!collided->right) {
        player->rect->x += PLAYER_SPEED;
        // }
    }

    if (app.keyboard[SDL_SCANCODE_LEFT]) {
        // if (!collided->left) {
        player->rect->x -= PLAYER_SPEED;
        // }
    }

    if (app.keyboard[SDL_SCANCODE_SPACE]) {
        fireBullets();
    }

    // free(collided);

    // player->rect->x += player->dx;
    // player->rect->y += player->dy;

}