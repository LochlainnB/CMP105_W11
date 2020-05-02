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
	void setTextureManager(TextureManager* textureManager);
	void setAudioManager(AudioManager* audioManager);

	void spawn(GameObject* object, float positionX, float positionY);
	void spawn(GameObject* object, sf::Vector2f position);
	void deleteEntities();

	void update(float dt);
	void handleInput(float dt);
	void render();
protected:
	std::vector<GameObject*> entities;
	Input* input;
	sf::RenderWindow* window;
	TextureManager* textureManager;
	AudioManager* audioManager;
};