#include "draw.h"
#include "SDL2/SDL_render.h"
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_image.h>



void prepareScene(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
    SDL_RenderClear(renderer);
}


void presentScene(SDL_Renderer* renderer) {
    SDL_RenderPresent(renderer);
}

SDL_Texture* loadTexture(char* filename, SDL_Renderer* renderer) {
    SDL_Texture* texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    texture = IMG_LoadTexture(renderer, filename);

    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load texture %s: %s", filename, IMG_GetError());
    }

    return texture;
}

void drawToScreen(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer) {
    SDL_Rect dest;


    dest.x = x;
    dest.y = y;


    if (SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h) != 0) {
        printf("Failed to get texture attrs: %s \n", SDL_GetError());
    }

    if (SDL_RenderCopy(renderer, texture, NULL, &dest) != 0) {
        printf("Failed to display texture: %s \n", SDL_GetError());
        // Failed to display texture: Invalid texture  ^
    }

}