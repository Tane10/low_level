#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    SDL_Renderer* renderer;
    SDL_Window* window;
    int up;
    int down;
    int left;
    int right;
    int fire;
} App;

typedef struct {
    unsigned int id;
    SDL_Texture* texture;
    SDL_Rect* rect;
    int speed;
    int dx;
    int dy;
    int health;
} Entity;

typedef struct {
    int top;
    int bottom;
    int right;
    int left;
} CollisionMap;

#endif