#include <structs.h>

void prepareScene(void) {
    SDL_SetRenderDrawColor(app.renderer, 99, 128, 255, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(void) {
    SDL_RenderPresent(app.renderer);
}