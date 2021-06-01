#pragma once
#include "pch.h"
#include "GraphicsEngineRenderer.hpp"
#include <SDL.h>

#ifndef SDL_ENGINE_RENDERER
#define SDL_ENGINE_RENDERER
class SDLEngineRenderer: public GraphicsEngineRenderer {
public:
	SDLEngineRenderer(const char* windowName, int x, int y, int w, int h);

	virtual ~SDLEngineRenderer();
	
	virtual void SetRenderDrawColor(int r, int g, int b, int a);

	virtual void RenderClear();

	virtual void RenderPresent();

	virtual void RenderCopy(void* texture, const void* srcRect, const void* destRect);

	virtual void RenderDrawRect(const void* rect);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};
#endif