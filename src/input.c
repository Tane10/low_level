#include "input.h"
#include <SDL2/SDL_events.h>


void doKeyDown(SDL_KeyboardEvent* event, App* app) {
    if (event->repeat == 0) {
        switch (event->keysym.scancode) {
        case SDL_SCANCODE_UP:
            app->up = 1;
            break;

        case SDL_SCANCODE_DOWN:
            app->down = 1;
            break;

        case SDL_SCANCODE_RIGHT:
            app->right = 1;
            break;

        case SDL_SCANCODE_LEFT:
            app->left = 1;
            break;

        default:
            break;

        }

    }

}

void doKeyUp(SDL_KeyboardEvent* event, App* app) {
    if (event->repeat == 0) {
        switch (event->keysym.scancode) {
        case SDL_SCANCODE_UP:
            app->up = 0;
            break;

        case SDL_SCANCODE_DOWN:
            app->down = 0;
            break;

        case SDL_SCANCODE_RIGHT:
            app->right = 0;
            break;

        case SDL_SCANCODE_LEFT:
            app->left = 0;
            break;

        default:
            break;

        }

    }

}


void doInput(App* app) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
            break;

        case SDL_KEYDOWN:
            doKeyDown(&event.key, app);
            break;

        case SDL_KEYUP:
            doKeyUp(&event.key, app);
            break;

        default:
            break;
        }
    }

}

