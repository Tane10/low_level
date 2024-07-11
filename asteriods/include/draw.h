#include "structs.h"
#include "SDL2/SDL_render.h"

#ifndef DRAW_H
#define DRAW_H


void prepareScene(SDL_Renderer* renderer);

void presentScene(SDL_Renderer* renderer);

SDL_Texture* loadTexture(char* filename, SDL_Renderer* renderer);

void drawToScreen(SDL_Texture* texture, SDL_Rect* rect, SDL_Renderer* renderer);


#endif