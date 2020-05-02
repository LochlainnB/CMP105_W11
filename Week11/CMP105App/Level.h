#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/TileMap.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Player.h"
#include <string>
#include <iostream>


class Level{
public:
	Level(std::vector<int> map, sf::Vector2u mapSize);
	~Level();

	//Setters
	void setInput(Input* input);
	void setWindow(sf::RenderWindow* window);
	void setTextureManager(TextureManager* textureManager);
	void setAudioManager(AudioManager* audioManager);
	void setGameState(GameState* gameState);

	void buildLevel();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	TextureManager* textureManager;
	AudioManager* audioManager;
	GameState* gameState;
	Manager manager;
	TileMap tileMap;
};