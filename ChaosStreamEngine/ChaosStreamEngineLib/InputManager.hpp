#pragma once
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <unordered_map>
#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

class InputManager {
public:
	~InputManager();
	static InputManager* getInstance();

	void init();

	/// <summary>
	/// Add an input to the queue
	/// </summary>
	/// <param name="input">input, specified by id. cannot be 0</param>
	void push(unsigned int input);

	/// <summary>
	/// Return the next input in the queue. Also sets the flag for that
	/// input (getInputDown will return true for that input, until
	/// clearInputFlags is called).
	/// </summary>
	/// <returns>the next input, or 0 if no input is found</returns>
	unsigned int pop();
	
	/// <summary>
	/// Returns the value of the flag for this input.
	/// </summary>
	/// <param name="input">input, specified by id. cannot be 0</param>
	/// <returns>true if pop() has returned this input since
	/// clearInputFlags was last called.</returns>
	bool getInputDown(unsigned int input);

	/// <summary>
	/// Resets the input flags.
	/// </summary>
	void clearInputFlags();

	void shutdown();
private:
	InputManager();
	static InputManager* instance;
	std::queue<unsigned int> inputQ;
	std::unordered_map<unsigned int, bool> flags;
	bool initialized;
};
#endif