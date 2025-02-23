#pragma once
#include "GameWindow.h"
#include <memory>

namespace AppInfo {
	static constexpr const char* WINDOW_NAME = "Sling Mas";
	static std::unique_ptr<GameWindow> mainWindow = std::make_unique<GameWindow>();
}