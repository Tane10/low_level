#ifndef STAGE_H
#define STAGE_H

#include "structs.h"
#include <SDL2/SDL_render.h>

void initStage(SDL_Renderer* ren);

static void initPlayer(Stage* stage, SDL_Renderer* ren);

#endif