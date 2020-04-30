#include "Manager.h"
#include <iostream>

Manager::Manager() {

}

Manager::~Manager() {
	for (int i = 0; i < entities.size(); i++) {
		delete entities[0];
	}
}

void Manager::setInput(Input* input) {
	this->input = input;
}

void Manager::setWindow(sf::RenderWindow* window) {
	this->window = window;
}

void Manager::spawn(GameObject* object) {
	entities.push_back(object);
	entities[entities.size() - 1]->setWindow(window);
	entities[entities.size() - 1]->setInput(input);
	entities[entities.size() - 1]->setEntities(&entities);
	entities[entities.size() - 1]->setTiles(&tiles);
	entities[entities.size() - 1]->setAlive(true);
}

void Manager::spawnTile(GameObject tile) {
	tiles.push_back(tile);
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
	for (int i = 0; i < tiles.size(); i++) {
		window->draw(tiles[i]);
	}
}