#include "structs.h"
#include <SDL2/SDL_events.h>

#ifndef INPUT_H
#define INPUT_H


void doInput(App* app);

void doKeyDown(SDL_KeyboardEvent* event, App* app);

void doKeyUp(SDL_KeyboardEvent* event, App* app);


#endif