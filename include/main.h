#ifndef MAIN_H
#define MAIN_H

#include "structs.h"
#include <SDL2/SDL.h>

int main(int argc, char* argv[]);

void cleanUp(Entity* ent, SDL_Window* window, SDL_Renderer* ren);

static void logic();

#endif