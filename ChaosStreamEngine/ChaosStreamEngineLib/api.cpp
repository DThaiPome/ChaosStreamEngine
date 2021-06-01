#include "pch.h"
#include <SDL.h>
#include "Engine.hpp"
#include "SDLEngineRenderer.hpp"
#include "InputManager.hpp"
#include <string>

Engine engine;

static void prog() {
	engine = Engine();
	SDLEngineRenderer* renderer = new SDLEngineRenderer(
		"Test", 100, 100, 800, 600
	);

	engine.InitializeSubSystems(renderer);
	engine.StartLoop(true);
	engine.Shutdown();
}

static InputManager* getInputManager() {
	return InputManager::getInstance();
}

static void pushToInputManager(int input) {
	if (input >= 0) {
		InputManager::getInstance()->push(static_cast<unsigned int>(input));
	}
}

extern "C" {
	__declspec(dllexport) void StartEngine() {
		prog();
	}

	__declspec(dllexport) void PushInput(int input) {
		pushToInputManager(input);
	}
}