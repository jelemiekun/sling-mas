#include "Background.h"

Background::Background() {}

Background* Background::getInstance() {
	static Background instance;
	return &instance;
}

void Background::input(SDL_Event& event) {

}

void Background::update() {

}

void Background::render() const {

}