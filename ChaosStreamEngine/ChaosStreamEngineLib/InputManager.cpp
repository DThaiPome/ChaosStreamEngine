#include "pch.h"
#include "InputManager.hpp"
#include <stdlib.h>
#include <queue>
#include <unordered_map>

InputManager* InputManager::instance = nullptr;

InputManager::InputManager() { }
InputManager::~InputManager() {

}

InputManager* InputManager::getInstance() {
	if (instance == nullptr) {
		instance = new InputManager();
	}
	return instance;
}

void InputManager::init() {
	this->initialized = true;
}

void InputManager::push(unsigned int input) {
	this->inputQ.push(input);
}

unsigned int InputManager::pop() {
	if (this->inputQ.empty()) {
		return 0;
	}
	unsigned int next = this->inputQ.front();
	this->inputQ.pop();
	this->flags[next] = true;
	return next;
}

bool InputManager::getInputDown(unsigned int input) {
	return this->flags[input];
}

void InputManager::clearInputFlags() {
	this->flags.clear();
}

void InputManager::shutdown() {
	while (!(this->inputQ.empty())) {
		this->inputQ.pop();
	}
	this->flags.clear();
	this->initialized = false;
}