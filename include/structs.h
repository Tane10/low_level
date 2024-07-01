#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>

typedef struct structs {
    SDL_Renderer* renderer;
    SDL_Window* window;

} App;

#endif