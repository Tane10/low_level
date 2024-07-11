#include "input.h"
#include "structs.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_log.h>


void doKeyDown(SDL_KeyboardEvent* event, App* app, int* speed) {
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

        case SDL_SCANCODE_B:
            *speed = 10;
            break;

        case SDL_SCANCODE_SPACE:
            app->fire = 1;
            break;
        default:
            break;

        }

    }

}

void doKeyUp(SDL_KeyboardEvent* event, App* app, int* speed) {
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

        case SDL_SCANCODE_B:
            *speed = 4;
            break;

        case SDL_SCANCODE_SPACE:
            app->fire = 0;
            break;
        default:
            break;

        }

    }

}


void doInput(App* app, Entity* entity) {
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

            doKeyDown(&event.key, app, &(entity->speed));
            break;

        case SDL_KEYUP:
            doKeyUp(&event.key, app, &(entity->speed));
            break;

        default:
            break;
        }
    }

}

