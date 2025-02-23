#pragma once
#include <SDL.h>

namespace FPSManager {
	void calculateAverageFPS(int& countFrame, Uint32& startTime);
	void capFPS(const Uint32& frameStart);
};

