#pragma once
#include <SDL.h>

class Game {
private:
	Game();

public:
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

	static Game* getInstance();

private:
	void initWindow();

public:
	void initAll();
	void input();
	void update(const float& deltaTime);
	void render() const;
};