#pragma once
#include <SDL.h>

class GameWindow {
private:
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	int mWindowID;
	int mWidth;
	int mHeight;
	bool mMouseFocus;
	bool mKeyboardFocus;
	bool mFullScreen;
	bool mMinimized;
	bool mShown;

private:
	bool initWindow(const int& windowWidth, const int& windowHeight, const bool& resizable);
	bool initRenderer();
	void initMemberVaribles(const int& windowWidth, const int& windowHeight);

public:
	GameWindow();
	~GameWindow();

	bool init(const int& windowWidth, const int& windowHeight, const bool& resizable);

	void input(SDL_Event& event);
	void renderClear() const;
	void renderPresent() const;

	void focus();
	void free();
	void toggleFullscreen();

	SDL_Renderer* getRenderer() const;
	int getWindowID() const;
	int getWidth() const;
	int getHeight() const;
	bool hasMouseFocus() const;
	bool hasKeyboardFocus() const;
	bool isMinimized() const;
	bool isShown() const;
};

