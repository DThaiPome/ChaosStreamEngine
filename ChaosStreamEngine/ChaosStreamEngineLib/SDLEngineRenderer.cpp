#include "pch.h"
#include "SDLEngineRenderer.hpp"

SDLEngineRenderer::SDLEngineRenderer(const char* windowName, int x, int y, int w, int h) : GraphicsEngineRenderer() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw "Failed to initialize SDL";
	}
	this->window = SDL_CreateWindow(windowName, x, y, w, h, SDL_WINDOW_SHOWN);
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

SDLEngineRenderer::~SDLEngineRenderer() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
}

void SDLEngineRenderer::SetRenderDrawColor(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

void SDLEngineRenderer::RenderClear() {
	SDL_RenderClear(this->renderer);
}

void SDLEngineRenderer::RenderPresent() {
	SDL_RenderPresent(this->renderer);
}

void SDLEngineRenderer::RenderCopy(void* texture, const void* srcRect, const void* destRect) {
	SDL_RenderCopy(this->renderer, static_cast<SDL_Texture*>(texture), static_cast<const SDL_Rect*>(srcRect), static_cast<const SDL_Rect*>(destRect));
}

void SDLEngineRenderer::RenderDrawRect(const void* rect) {
	SDL_RenderDrawRect(this->renderer, static_cast<const SDL_Rect*>(rect));
}