#ifndef INPUT_H
#define INPUT_H

#include "structs.h"
#include <SDL2/SDL_events.h>



void inputHandler(void);

void keyDownHandler(SDL_KeyboardEvent* event);

void keyUpHandler(SDL_KeyboardEvent* event);


#endif