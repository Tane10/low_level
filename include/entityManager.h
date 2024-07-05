#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "structs.h"

Entity* buildEntity(char* texture, SDL_Renderer* ren);

unsigned int generateUniqueId();

void destroyEntity(Entity* id);

#endif