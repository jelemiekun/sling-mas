#pragma once
#include <SDL.h>

class Player {
private:
	Player();

public:
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
    Player(Player&&) = delete;
    Player& operator=(Player&&) = delete;

    static Player* getInstance();

private:
    SDL_Rect player;

public:
    void init();

    void input(const SDL_Event& event);
    void update(const float& deltaTime);
    void render() const;
};

