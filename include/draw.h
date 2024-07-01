#ifndef DRAW_H
#define DRAW_H

void prepareScene(App* app);

void presentScene(App* app);

SDL_Texture* loadTexture(char* filename, App* app);

void blit(SDL_Texture* texture, int x, int y, App* app);

#endif