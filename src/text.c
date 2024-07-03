#include "text.h"
#include "draw.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_ttf.h>


void drawText(SDL_Renderer* ren) {
    SDL_Color colour = { 255, 255, 255 };
    // SDL_Color bgColor = { 160,  32,  240 };

    TTF_Font* font = TTF_OpenFont("ARIAL.TTF", 10);

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "hello", colour);

    SDL_Rect textLocation = { 400,400,0,0 };

    SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, textSurface);
    SDL_FreeSurface(textSurface);

    drawToScreen(texture, &textLocation, ren);



    // SDL_QueryTexture(texture, NULL, NULL, &textLocation.w, &textLocation.h);

    // SDL_UpperBlit(textSurface, NULL, screen, &textLocation);

    // SDL_FreeSurface(textSurface);

    TTF_CloseFont(font);

}