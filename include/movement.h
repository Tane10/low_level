#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "structs.h"
#include <SDL2/SDL_video.h>

void movementHandler(void);

CollisionMap* hasCollidedWithBorder(SDL_Window* window, SDL_Rect* entityRect);

#endif