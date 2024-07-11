#include "structs.h"

#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

Entity* buildEntity(char* texture, SDL_Renderer* ren);

unsigned int generateUniqueId();

void destroyEntity(Entity* id);

#endif