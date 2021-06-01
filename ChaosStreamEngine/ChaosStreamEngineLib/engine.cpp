#include "pch.h"
#include <SDL.h>

extern "C" {

	int count;

	__declspec(dllexport) void StartEngine() {
		SDL_Init(SDL_INIT_VIDEO);
		
		SDL_Window* window = SDL_CreateWindow("Test", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		bool running = true;
		while (running) {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					running = false;
				}
			}

			count++;
			count %= 10000;

			SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
		}

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	__declspec(dllexport) int GetCount() {
		return count;
	}
}