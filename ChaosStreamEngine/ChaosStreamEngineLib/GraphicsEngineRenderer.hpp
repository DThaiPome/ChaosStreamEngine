#pragma once
#include "pch.h"

#ifndef GRAPHICS_ENGINE_RENDERER_HPP
#define GRAPHICS_ENGINE_RENDERER_HPP
class GraphicsEngineRenderer {
public:
	GraphicsEngineRenderer() { }
	virtual ~GraphicsEngineRenderer() { }

	virtual void SetRenderDrawColor(int r, int g, int b, int a) = 0;
	virtual void RenderClear() = 0;
	virtual void RenderPresent() = 0;

	/// <summary>
	/// Render a selection from a texture to somewhere on the screen.
	/// </summary>
	/// <param name="texture">pointer to the texture memory</param>
	/// <param name="srcRect">pointer to the rect that represents the region to copy</param>
	/// <param name="destRect">pointer to the rect that represents the destination region on the window</param>
	virtual void RenderCopy(void* texture, const void* srcRect, const void* destRect) = 0;

	/// <summary>
	/// Draws a rectangle on the screen.
	/// </summary>
	/// <param name="rect">pointer to the rect that represents the destination region</param>
	virtual void RenderDrawRect(const void* rect) = 0;
};
#endif