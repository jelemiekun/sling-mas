#include <SDL.h>
#include "Game.h"
#include "FPSManager.h"

int SDL_main(int argc, char* argv[]) {
    Game* game = Game::getInstance();
    
    game->initAll();

    int countFrame = 0;
    Uint32 startTime = SDL_GetTicks();
    Uint32 lastFrameTime = SDL_GetTicks();

    while (game->isRunning()) {
        Uint32 frameStart = SDL_GetTicks();

        float deltaTime = (frameStart - lastFrameTime) / 1000.0f;
        lastFrameTime = frameStart;

        game->input();
        game->update(deltaTime);
        game->render();

        FPSManager::calculateAverageFPS(countFrame, startTime);
        FPSManager::capFPS(frameStart);
    }

    return 0;
}