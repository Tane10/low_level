#ifndef STAGE_H
#define STAGE_H

#include "structs.h"
#include <SDL2/SDL_render.h>

void initStage(SDL_Renderer* ren);

Entity* initPlayer(Stage* stage, SDL_Renderer* ren);

static void logic(void);

static void doPlayer(void);

static void doBullets(void);

static void fireBullets(void);

Entity* getPlayer(void);


#endif