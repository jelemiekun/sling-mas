#include "Player.h"
#include "AppInfo.h"
#include "GameWindow.h"
#include "Game.h"
#include "spdlog/spdlog.h"

constexpr static int PADDING_LIMIT = 30;

Player::Player() {}

Player* Player::getInstance() {
	static Player instance;
	return &instance;
}

void Player::init() {
	spdlog::info("Initializing player.");

	player.x = PADDING_LIMIT;
	player.y = PADDING_LIMIT;
	player.w = 20;
	player.h = 20;

	spdlog::info("x, y: {} {}", player.x, player.y);
	spdlog::info("Player initialized.");
}

void Player::input(const SDL_Event& event) {

}

void Player::update(const float& deltaTime) {

}

void Player::render() const {
	spdlog::info("rendering player");
	SDL_SetRenderDrawColor(AppInfo::mainWindow->getRenderer(), 0, 255, 0, 255);
	SDL_RenderFillRect(AppInfo::mainWindow->getRenderer(), &player);
}