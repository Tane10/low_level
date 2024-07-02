#include "structs.h"
#include "SDL2/SDL_render.h"

#ifndef DRAW_H
#define DRAW_H


void prepareScene(App* app);

void presentScene(App* app);

SDL_Texture* loadTexture(char* filename, SDL_Renderer* renderer);

void drawToScreen(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer);

#endif