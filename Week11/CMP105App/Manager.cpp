#include "Manager.h"
#include <iostream>

Manager::Manager() {

}

Manager::~Manager() {
	for (int i = 0; i < entities.size(); i++) {
		delete entities[i];
	}
}

void Manager::setInput(Input* input) {
	this->input = input;
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->setInput(input);
	}
}

void Manager::setWindow(sf::RenderWindow* window) {
	this->window = window;
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->setWindow(window);
	}
}

void Manager::setTextureManager(TextureManager* textureManager) {
	this->textureManager = textureManager;
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->setTextureManager(textureManager);
	}
}

void Manager::setAudioManager(AudioManager* audioManager) {
	this->audioManager = audioManager;
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->setAudioManager(audioManager);
	}
}

void Manager::spawn(GameObject* object, float positionX, float positionY) {
	spawn(object, sf::Vector2f(positionX, positionY));
}

void Manager::spawn(GameObject* object, sf::Vector2f position) {
	entities.push_back(object);
	entities[entities.size() - 1]->setPosition(position);
	entities[entities.size() - 1]->setWindow(window);
	entities[entities.size() - 1]->setInput(input);
	entities[entities.size() - 1]->setEntities(&entities);
	entities[entities.size() - 1]->setTextureManager(textureManager);
	entities[entities.size() - 1]->setAudioManager(audioManager);
	entities[entities.size() - 1]->setAlive(true);
}

void Manager::update(float dt) {
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->update(dt);

		if (!entities[i]->isAlive()) {
			entities.erase(entities.begin() + i);
			i--;
		}
	}
}

void Manager::deleteEntities() {
	for (int i = 0; i < entities.size(); i++) {
		delete entities[i];
	}
	entities.clear();
}

void Manager::handleInput(float dt) {
	//self

	//entities
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->handleInput(dt);
	}
}

void Manager::render() {
	for (int i = 0; i < entities.size(); i++) {
		window->draw(*entities[i]);
	}
}