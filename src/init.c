#include "init.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "defs.h"



void initSDL(App* app) {
    IMG_Init(IMG_INIT_PNG);

    int renderFlags, windowFlags;

    renderFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't init SDL: %s \n", SDL_GetError());
        exit(1);
    }

    app->window = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!app->window) {
        printf("Failed to open window: %d X %d window: %s \n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app->renderer = SDL_CreateRenderer(app->window, -1, renderFlags);

    if (!app->renderer) {
        printf("Failed to create renderer: %s \n", SDL_GetError());
        exit(1);
    }

    // if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    //     printf("Failed to initialize SDL_image: %s\n", IMG_GetError());
    //     exit(1);
    // }
}