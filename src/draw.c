#include "structs.h"
#include "draw.h"

void prepareScene(void) {
    // RGBA
    // rgba(255, 197, 0, 1)
    SDL_SetRenderDrawColor(app.renderer, 255, 197, 0, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(void) {
    SDL_RenderPresent(app.renderer);
}