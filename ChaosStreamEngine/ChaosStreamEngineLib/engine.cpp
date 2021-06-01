#include "pch.h"
#include "Engine.hpp"
#include "InputManager.hpp"
#include <SDL.h>
#include <stdio.h>
#include <iostream>

Engine::Engine() {

}

Engine::~Engine() {
}

void Engine::InitializeSubSystems(GraphicsEngineRenderer* renderer) {
	this->renderer = renderer;
	InputManager::getInstance()->init();
}

void Engine::Shutdown() {
	InputManager::getInstance()->shutdown();
	delete this->renderer;
}

bool Engine::CheckIfRunning() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

void Engine::StartLoop(bool popInputs) {
	InputManager* input = InputManager::getInstance();

	bool running = true;
	while (running) {
		this->renderer->SetRenderDrawColor(0x0, 0x0, 0x0, 0xFF);
		this->renderer->RenderClear();
		this->renderer->RenderPresent();

		if (popInputs) {
			unsigned int i;
			while((i = input->pop()) != 0) { 
				std::cout << i << std::endl;
			}
		}

		// UPDATE
		// RENDER
		// FRAME DELAY

		if (popInputs) {
			input->clearInputFlags();
		}

		running = this->CheckIfRunning();
	}
}