#include "structs.h"
#include <SDL2/SDL_events.h>

#ifndef INPUT_H
#define INPUT_H


void doInput(App* app, Entity* entity);

void doKeyDown(SDL_KeyboardEvent* event, App* app, int* speed);

void doKeyUp(SDL_KeyboardEvent* event, App* app, int* speed);


#endif