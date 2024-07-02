#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    SDL_Renderer* renderer;
    SDL_Window* window;
} App;

typedef struct {
    int x;
    int y;
    SDL_Texture* texture;
} Entity;

#endif