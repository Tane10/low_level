#include "input.h"
#include "structs.h"
#include "globals.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_log.h>


void keyDownHandler(SDL_KeyboardEvent* event) {
    if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS) {
        app.keyboard[event->keysym.scancode] = 1;
    }

}

void keyUpHandler(SDL_KeyboardEvent* event) {
    if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS) {
        app.keyboard[event->keysym.scancode] = 0;
    }

}


void inputHandler(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
            break;

        case SDL_KEYDOWN:
            // quick exit
            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                exit(0);
            }

            keyDownHandler(&event.key);
            break;

        case SDL_KEYUP:
            keyUpHandler(&event.key);
            break;

        default:
            break;
        }
    }

}

