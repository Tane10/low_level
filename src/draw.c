#include "structs.h"
#include "draw.h"

void prepareScene(App* app) {
    // RGBA
    SDL_SetRenderDrawColor(app->renderer, 0, 98, 255, 255);
    SDL_RenderClear(app->renderer);
}

void presentScene(App* app) {
    SDL_RenderPresent(app->renderer);
}