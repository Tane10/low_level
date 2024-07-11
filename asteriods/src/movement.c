#include <SDL2/SDL_video.h>
#include <structs.h>
#include <SDL2/SDL_log.h>

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



void movement(App* app, SDL_Rect* entityRect, int* speed) {

    CollisionMap* collided = hasCollidedWithBorder(app->window, entityRect);


    if (app->up) {
        if (!collided->top) {
            entityRect->y -= *speed;
        }
    }

    if (app->down) {
        if (!collided->bottom) {
            entityRect->y += *speed;
        }
    }

    if (app->right) {
        if (!collided->right) {
            entityRect->x += *speed;
        }
    }

    if (app->left) {
        if (!collided->left) {
            entityRect->x -= *speed;
        }
    }

    free(collided);

}