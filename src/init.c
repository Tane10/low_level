#include "init.h"
#include "defs.h"
#include "globals.h"
#include "structs.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>



void initSDL() {
    // IMG_Init(IMG_INIT_PNG);

    int renderFlags, windowFlags;

    renderFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't init SDL: %s \n", SDL_GetError());
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "IMG_Init Error: %s", IMG_GetError());
        exit(1);
    }

    app.window = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!app.window) {
        printf("Failed to open window: %d X %d window: %s \n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, renderFlags);

    if (!app.renderer) {
        printf("Failed to create renderer: %s \n", SDL_GetError());
        exit(1);
    }

    if (TTF_Init() != 0) {
        printf("Failed to create TTF: %s \n", SDL_GetError());
        exit(1);
    }

}