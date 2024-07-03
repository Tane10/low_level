#include "main.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"

#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    App app;
    Entity player;

    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));

    initSDL(&app);

    player.x = 100;
    player.y = 100;
    player.texture = loadTexture("assets/pixel_ship.png", app.renderer);

    if (!player.texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load texture");
        return 1;
    }

    while (1) {
        prepareScene(app.renderer);

        doInput(&app);

        movement(&player, &app);

        drawToScreen(player.texture, player.x, player.y, app.renderer);

        presentScene(app.renderer);

        SDL_Delay(16);
    }

    return 0;
}