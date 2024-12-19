#include <SDL.h>
#include "Game.h"

int SDL_main(int argc, char* argv[]) {
    Game* game = Game::getInstance();
    
    game->initAll();

    while (game->isRunning()) {
        game->input();
        game->update(1.0f);
        game->render();
    }

    return 0;
}