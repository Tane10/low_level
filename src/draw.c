#include "structs.h"
#include "draw.h"
#include <SDL2/SDL_image.h>

void prepareScene(App* app) {
    // RGBA
    SDL_SetRenderDrawColor(app->renderer, 0, 98, 255, 255);
    SDL_RenderClear(app->renderer);
}

void presentScene(App* app) {
    SDL_RenderPresent(app->renderer);
}


SDL_Texture* loadTexture(char* filename, App* app) {
    SDL_Texture* texture;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    texture = IMG_LoadTexture(app->renderer, filename);

    return texture;
}

void blit(SDL_Texture* texture, int x, int y, App* app) {
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app->renderer, texture, NULL, &dest);

}

