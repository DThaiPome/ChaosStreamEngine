#pragma once
#include "pch.h"
#include "GraphicsEngineRenderer.hpp"

#ifndef ENGINE_HPP
#define ENGINE_HPP
class Engine {
public:
	Engine();
	~Engine();

	void InitializeSubSystems(GraphicsEngineRenderer* renderer);

	//TODO: Make a config for this or something
	void StartLoop(bool popInputs);

	void Shutdown();

private:
	bool CheckIfRunning();

	GraphicsEngineRenderer* renderer;
};
#endif