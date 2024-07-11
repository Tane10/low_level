#include <SDL2/SDL_video.h>
#include "structs.h"

#ifndef MOVEMENT_H
#define MOVEMENT_H

int movement(App* app, SDL_Rect* entityRect, int* speed);

CollisionMap* hasCollidedWithBorder(SDL_Window* window, SDL_Rect* entityRect);

#endif