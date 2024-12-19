#include "Game.h"
#include "GameWindow.h"
#include <spdlog/spdlog.h>
#include <memory>

static std::unique_ptr<GameWindow> mainWindow = std::make_unique<GameWindow>;

Game::Game() : running(false) {}

Game* Game::getInstance() {
	static Game instance;
	return &instance;
}

bool Game::initWindow() {
	return mainWindow.init(640, 480, true);
}

void Game::initAll() {
	if (initWindow())
		running = true;
}

void Game::input() {
	while (SDL_PollEvent(&event)) {
		mainWindow.input(event);
	}
}

void Game::update(const float& deltaTime) {

}

void Game::render() const {
	mainWindow.render();
}

bool Game::isRunning() const {
	return running;
}

void Game::setRunning(const bool& isRunning) {
	spdlog::info("Setting running game to {} ", isRunning);
	running = false;
}