#include "Level.h"

Level::Level()
{
	// initialise game objects
	manager.setInput(input);
	manager.setWindow(window);
	manager.spawn(new Player);
	tileMap.setManager(&manager);
	tileMap.setTileSize(32, 32);
	tileMap.setTileSet(tileSet.getTiles());
	std::vector<int> map {
	47, 47, 47, 47, 47,
	47, 47, 3, 47, 47,
	0, 1, 13, 1, 2,
	12, 13, 13, 13, 14,
	12, 13, 13, 13, 14
	};
	tileMap.setTileMap(map, sf::Vector2u(5, 5));
	tileMap.setPosition(sf::Vector2f(0, 408));
	tileMap.buildLevel();
}

Level::~Level()
{

}

//Setters
void Level::setInput(Input* input) {
	this->input = input;
}

void Level::setWindow(sf::RenderWindow* window) {
	this->window = window;
}

void Level::setAudioManager(AudioManager* audioManager) {
	this->audioManager = audioManager;
}

void Level::setGameState(GameState* gameState) {
	this->gameState = gameState;
}

// handle user input
void Level::handleInput(float dt)
{
	manager.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	manager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	manager.render();
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}