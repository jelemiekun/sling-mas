#pragma once
#include <SDL.h>

class Background {
private:
	Background();

public:
	Background(const Background&) = delete;
	Background& operator=(const Background&) = delete;
	Background(Background&&) = delete;
	Background& operator=(Background&&) = delete;

	static Background* getInstance();

public:
	void input(SDL_Event& event);
	void update();
	void render() const;
};

