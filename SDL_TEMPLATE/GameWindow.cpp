#include "GameWindow.h"
#include "AppInfo.h"
#include "Game.h"
#include <spdlog/spdlog.h>
#include <spdlog/logger.h>

GameWindow::GameWindow() : mWindow(nullptr), mRenderer(nullptr), mWindowID(-1),
mWidth(0), mHeight(0), mMouseFocus(false), mKeyboardFocus(false),
mFullScreen(false), mMinimized(false), mShown(false) {
}

GameWindow::~GameWindow() {
    free();
}

bool GameWindow::initWindow(const int& windowWidth, const int& windowHeight, const bool& resizable) {
    int flags = resizable ? (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE) : SDL_WINDOW_SHOWN;

    mWindow = SDL_CreateWindow(
        AppInfo::WINDOW_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        windowWidth,
        windowHeight,
        flags
    );

    if (mWindow) {
        mWindowID = SDL_GetWindowID(mWindow);

        spdlog::info("Window {} created!", mWindowID);
        return true;
    } else {
        spdlog::error("Failed to create window: {}", SDL_GetError());
        return false;
    }
}

bool GameWindow::initRenderer() {
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (mRenderer) {
        spdlog::info("Window renderer for window {} created!", mWindowID);
        return true;
    } else {
        spdlog::error("Failed to create renderer for window {}: {}", mWindowID, SDL_GetError());
        return false;
    }
}

void GameWindow::initMemberVaribles(const int& windowWidth, const int& windowHeight) {
    mMouseFocus = mKeyboardFocus = true;
    mShown = true;
    mMinimized = false;
    mWidth = windowWidth;
    mHeight = windowHeight;
}

bool GameWindow::init(const int& windowWidth, const int& windowHeight, const bool& resizable) {
    bool initSuccess = initWindow(windowWidth, windowHeight, resizable) && initRenderer();

    if (initSuccess) initMemberVaribles(windowWidth, windowHeight);

    return initSuccess;
}

void GameWindow::input(SDL_Event& event) {
    if (event.type == SDL_WINDOWEVENT && event.window.windowID == mWindowID) {
        switch (event.window.event) {
        case SDL_WINDOWEVENT_SHOWN:
            mShown = true;
            break;
        case SDL_WINDOWEVENT_HIDDEN:
            mShown = false;
            break;
        case SDL_WINDOWEVENT_ENTER:
            mMouseFocus = true;
            break;
        case SDL_WINDOWEVENT_LEAVE:
            mMouseFocus = false;
            break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            mKeyboardFocus = true;
            break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
            mKeyboardFocus = false;
            break;
        case SDL_WINDOWEVENT_MINIMIZED:
            mMinimized = true;
            break;
        case SDL_WINDOWEVENT_RESTORED:
            mMinimized = false;
            break;
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            mWidth = event.window.data1;
            mHeight = event.window.data2;
            SDL_RenderPresent(mRenderer);
            break;
        case SDL_WINDOWEVENT_CLOSE:
            SDL_HideWindow(mWindow);
            mShown = false;
            break;
            
        }
    } else if (event.type == SDL_QUIT && mWindowID == 1) {
        Game::getInstance()->setRunning(false);
    } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F11 && mWindowID == 1) {
        toggleFullscreen();
    }
}

void GameWindow::render() const {
    if (!mMinimized) {
        SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0);
        SDL_RenderClear(mRenderer);
        SDL_RenderPresent(mRenderer);
    }
}

void GameWindow::focus() {
    if (!mShown) {
        SDL_ShowWindow(mWindow);
    }
    SDL_RaiseWindow(mWindow);
}

void GameWindow::free() {
    if (mWindow) {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
    }
    if (mRenderer) {
        SDL_DestroyRenderer(mRenderer);
        mRenderer = nullptr;
    }
    mWidth = mHeight = 0;
}

void GameWindow::toggleFullscreen() {
    if (mFullScreen) {
        SDL_SetWindowFullscreen(mWindow, 0);
        mFullScreen = false;
    } else {
        SDL_SetWindowFullscreen(mWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
        mFullScreen = true;
    }
}


SDL_Renderer* GameWindow::getRenderer() const { return mRenderer; }
int GameWindow::getWindowID() const { return mWindowID; }
int GameWindow::getWidth() const { return mWidth; }
int GameWindow::getHeight() const { return mHeight; }
bool GameWindow::hasMouseFocus() const { return mMouseFocus; }
bool GameWindow::hasKeyboardFocus() const { return mKeyboardFocus; }
bool GameWindow::isMinimized() const { return mMinimized; }
bool GameWindow::isShown() const { return mShown; }