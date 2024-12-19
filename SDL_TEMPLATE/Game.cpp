#include "Game.h"
#include "GameWindow.h"

static GameWindow mainWindow;

Game::Game() {}

Game* Game::getInstance() {
	static Game instance;
	return &instance;
}

void Game::initWindow() {
	mainWindow.init(640, 480, true);
}

void Game::initAll() {
	initWindow();
}

void Game::input() {

}

void Game::update(const float& deltaTime) {

}

void Game::render() const {

}