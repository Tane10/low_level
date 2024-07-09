#ifndef STAGE_H
#define STAGE_H

#include "structs.h"
#include <SDL2/SDL_render.h>

void initStage(SDL_Renderer* ren);

Entity* initPlayer(Stage* stage, SDL_Renderer* ren);

Entity* getPlayer(void);

void fireBullets(void);

/** Static functions
 * static void logic(void);
 * static void doPlayer(void);
 * static void doBullets(void);
 * static void fireBullets(void);
 * static void draw(void);
 * static void drawPlayer(void);
 * static void drawBullets(void);
*/
#endif