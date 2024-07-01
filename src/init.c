#include <SDL2/SDL.h>
#include <defs.h>
#include <structs.h>
#include <init.h>


SDL_Texture* loadTexture(char* filename, App* app) {
    SDL_Texture* texture;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    texture = IMG_loadTexture(app->renderer, filename);

    return texture;
}


void initSDL(App* app) {
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error init SDL... \n");
        exit(0);
    }

    app->window = SDL_CreateWindow("low level", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!app->window) {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }


    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");


    app->renderer = SDL_CreateRenderer(app->window, -1, rendererFlags);

    if (!app->renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}