#include "LevelManager.h"
#include <iostream>

LevelManager::LevelManager() {

}

LevelManager::~LevelManager() {
	for (int i = 0; i < static_cast<int>(State::NUM_STATES); i++) {
		delete levels[i];
	}
}

void LevelManager::setInput(Input* input) {
	this->input = input;
	for (int i = 0; i < static_cast<int>(State::NUM_STATES); i++) {
		levels[i]->setInput(input);
	}
}

void LevelManager::setWindow(sf::RenderWindow* window) {
	this->window = window;
	for (int i = 0; i < static_cast<int>(State::NUM_STATES); i++) {
		levels[i]->setWindow(window);
	}
}

void LevelManager::setAudioManager(AudioManager* audioManager) {
	this->audioManager = audioManager;
	for (int i = 0; i < static_cast<int>(State::NUM_STATES); i++) {
		levels[i]->setAudioManager(audioManager);
	}
}

void LevelManager::setGameState(GameState* gameState) {
	this->gameState = gameState;
	for (int i = 0; i < static_cast<int>(State::NUM_STATES); i++) {
		levels[i]->setGameState(gameState);
	}
}

void LevelManager::newLevel(State levelType) {
	int index = static_cast<int>(levelType);
	delete levels[index];
	levels[index] = new Level();
	levels[index]->setWindow(window);
	levels[index]->setInput(input);
	levels[index]->setAudioManager(audioManager);
	levels[index]->setGameState(gameState);
}

void LevelManager::update(float dt) {
	levels[static_cast<int>(gameState->getCurrentState())]->update(dt);
}

void LevelManager::handleInput(float dt) {
	levels[static_cast<int>(gameState->getCurrentState())]->handleInput(dt);
}

void LevelManager::render() {
	levels[static_cast<int>(gameState->getCurrentState())]->render();
}