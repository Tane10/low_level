#include <SDL2/SDL_events.h>
#include "input.h"


void doInput(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
            break;

        default:
            break;
        }
    }
}