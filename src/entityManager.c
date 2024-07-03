#include "entityManager.h"
#include "structs.h"
#include "draw.h"

#include <SDL2/SDL_log.h>

unsigned int generateUniqueId() {
    static unsigned int currentId = 0;
    return ++currentId;
}

void destroyEntity(Entity* id) {
    free(id);
}

Entity* buildEntity(char* texture, SDL_Renderer* ren) {
    SDL_Rect rect;

    Entity* npc = malloc(sizeof(Entity));

    npc->rect = &rect;
    npc->rect->x = 100;
    npc->rect->y = 100;
    npc->rect->w = 50;
    npc->rect->h = 50;

    npc->texture = loadTexture(texture, ren);
    if (!npc->texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load texture");
        exit(1);
    }

    return npc;
}