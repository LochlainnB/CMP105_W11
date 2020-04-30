#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "math.h"
#include <vector>

class Manager {
public:
	Manager();
	~Manager();

	void setWindow(sf::RenderWindow* window);
	void setInput(Input* input);

	void spawn(GameObject* object);
	void spawnTile(GameObject tile);
	void update(float dt);
	void handleInput(float dt);
	void render();
protected:
	std::vector<GameObject> tiles;
	std::vector<GameObject*> entities;
	Input* input;
	sf::RenderWindow* window;
};