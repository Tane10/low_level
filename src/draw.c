#include "draw.h"
#include "SDL2/SDL_render.h"
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_image.h>



void prepareScene(App* app) {
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
    SDL_RenderClear(app->renderer);
}


void presentScene(App* app) {
    SDL_RenderPresent(app->renderer);
}

SDL_Texture* loadTexture(char* filename, SDL_Renderer* renderer) {
    SDL_Texture* texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    texture = IMG_LoadTexture(renderer, filename);

    return texture;
}

void drawToScreen(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer) {
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.y);

    SDL_RenderCopy(renderer, texture, NULL, &dest);

}