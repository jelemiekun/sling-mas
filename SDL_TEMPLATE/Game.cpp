#include "Game.h"
#include "GameWindow.h"
#include "Background.h"
#include "Player.h"
#include "AppInfo.h"
#include <spdlog/spdlog.h>

static Player* player = Player::getInstance();

Game::Game() : running(false) {}

Game* Game::getInstance() {
	static Game instance;
	return &instance;
}

bool Game::initWindow() {
	spdlog::info("Initializing main window.");
	return AppInfo::mainWindow->init(1080, 720, true);
}

void Game::initAll() {
	if (initWindow()) {
		spdlog::info("Main window initialized.");
		player->init();

		running = true;
	}
}

void Game::input() {
	while (SDL_PollEvent(&event)) {
		AppInfo::mainWindow->input(event);
		Background::getInstance()->input(event);
		player->input(event);
	}
}

void Game::update(const float& deltaTime) {
	Background::getInstance()->update();
	player->update(deltaTime);
}

void Game::render() const {
	AppInfo::mainWindow->renderClear();

	Background::getInstance()->render();
	player->render();

	AppInfo::mainWindow->renderPresent();
}

bool Game::isRunning() const {
	return running;
}

void Game::setRunning(const bool& isRunning) {
	spdlog::info("Setting running game to {} ", isRunning);
	running = false;
}