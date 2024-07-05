#ifndef STRUCTS_H
#define STRUCTS_H

#include "defs.h"

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>


typedef struct {
    void (*logic)(void);
    void (*draw)(void);
} Delegate;

typedef struct {
    SDL_Renderer* renderer;
    SDL_Window* window;
    int keyboard[MAX_KEYBOARD_KEYS];
    Delegate delegate;
} App;

// creating an Entity linked-list see struct Entity* next
typedef struct {
    float x;
    float y;
    int w;
    int h;
    float dx;
    float dy;
    int health;
    int reload;
    SDL_Texture* texture;
    SDL_Rect* rect;
    struct Entity* next;
} Entity;


// controller to linked-list
typedef struct {
    Entity fighterHead, * fighterTail;
    Entity bulletHead, * bulletTail;
} Stage;

typedef struct {
    int top;
    int bottom;
    int right;
    int left;
} CollisionMap;

#endif


// typedef struct {
//     unsigned int id;
//     SDL_Texture* texture;
//     SDL_Rect* rect;
//     int dx;
//     int dy;
//     int health;
// } Entity;


// typedef struct {
//     SDL_Renderer* renderer;
//     SDL_Window* window;
//     int up;
//     int down;
//     int left;
//     int right;
//     int fire;
// } App;
