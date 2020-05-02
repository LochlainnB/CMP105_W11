#pragma once
#include "Level.h"
#include "math.h"
#include <vector>

class LevelManager {
public:
	LevelManager();
	~LevelManager();

	//Set the window which is passed to all levels
	void setWindow(sf::RenderWindow* window);
	//Set the input which is passed to all levels
	void setInput(Input* input);
	//Set the texture manager
	void setTextureManager(TextureManager* textureManager);
	//Set the audio manager which is passed to all levels
	void setAudioManager(AudioManager* audioManager);
	//Set the game state which is passed to all levels
	void setGameState(GameState* gameState);

	//Create a new level
	void newLevel(State levelType, std::vector<int> map, sf::Vector2u mapSize);
	//Update active levels
	void update(float dt);
	//Handle input on active levels
	void handleInput(float dt);
	void render();
protected:
	Level* levels[static_cast<int>(State::NUM_STATES)]; //length = num items in State enum
	int menuLevel;
	int creditsLevel;
	Input* input;
	sf::RenderWindow* window;
	TextureManager* textureManager;
	AudioManager* audioManager;
	GameState* gameState;
};