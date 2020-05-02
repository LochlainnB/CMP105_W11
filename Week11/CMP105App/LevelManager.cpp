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
		if (levels[i] != nullptr) {
			levels[i]->setInput(input);
		}
	}
}

void LevelManager::setWindow(sf::RenderWindow* window) {
	this->window = window;
	for (int i = 0; i < static_cast<int>(State::NUM_STATES); i++) {
		if (levels[i] != nullptr) {
			levels[i]->setWindow(window);
		}
	}
}

void LevelManager::setTextureManager(TextureManager* textureManager) {
	this->textureManager = textureManager;
	for (int i = 0; i < static_cast<int>(State::NUM_STATES); i++) {
		if (levels[i] != nullptr) {
			levels[i]->setTextureManager(textureManager);
		}
	}
}

void LevelManager::setAudioManager(AudioManager* audioManager) {
	this->audioManager = audioManager;
	for (int i = 0; i < static_cast<int>(State::NUM_STATES); i++) {
		if (levels[i] != nullptr) {
			levels[i]->setAudioManager(audioManager);
		}
	}
}

void LevelManager::setGameState(GameState* gameState) {
	this->gameState = gameState;
	for (int i = 0; i < static_cast<int>(State::NUM_STATES); i++) {
		if (levels[i] != nullptr) {
			levels[i]->setGameState(gameState);
		}
	}
}

void LevelManager::newLevel(State levelType, std::vector<int> map, sf::Vector2u mapSize) {
	int index = static_cast<int>(levelType);
	delete levels[index];
	levels[index] = new Level(map, mapSize);
	levels[index]->setWindow(window);
	levels[index]->setInput(input);
	levels[index]->setTextureManager(textureManager);
	levels[index]->setAudioManager(audioManager);
	levels[index]->setGameState(gameState);
	levels[index]->buildLevel();
}

void LevelManager::update(float dt) {
	int index = static_cast<int>(gameState->getCurrentState());
	if (levels[index] != nullptr) {
		levels[index]->update(dt);
	}
}

void LevelManager::handleInput(float dt) {
	//game state transitions
	if (gameState->getCurrentState() == State::MENU && input->isKeyDown(sf::Keyboard::Enter)) {
		levels[static_cast<int>(State::LEVEL)]->buildLevel();
		gameState->setCurrentState(State::LEVEL);
		input->setKeyUp(sf::Keyboard::Enter);
		//music
		audioManager->playMusicbyName("cantina");
		audioManager->getMusic()->setLoop(true);
	}
	else if (gameState->getCurrentState() == State::LEVEL && input->isKeyDown(sf::Keyboard::P)) {
		gameState->setCurrentState(State::PAUSE);
		input->setKeyUp(sf::Keyboard::P);
		//music
		audioManager->getMusic()->pause();
	}
	else if (gameState->getCurrentState() == State::PAUSE && input->isKeyDown(sf::Keyboard::P)) {
		gameState->setCurrentState(State::LEVEL);
		input->setKeyUp(sf::Keyboard::P);
		//music
		audioManager->getMusic()->play();
	}
	else if (gameState->getCurrentState() == State::PAUSE && input->isKeyDown(sf::Keyboard::Escape)) {
		gameState->setCurrentState(State::MENU);
		input->setKeyUp(sf::Keyboard::Escape);
		//music
		audioManager->getMusic()->stop();
	}

	int index = static_cast<int>(gameState->getCurrentState());
	if (levels[index] != nullptr) {
		levels[index]->handleInput(dt);
	}
}

void LevelManager::render() {
	int index = static_cast<int>(gameState->getCurrentState());
	if (levels[index] != nullptr) {
		levels[index]->render();
	}
}