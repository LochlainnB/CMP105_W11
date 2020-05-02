#include "Level.h"

Level::Level(std::vector<int> map, sf::Vector2u mapSize)
{
	// initialise game objects
	manager.setAudioManager(audioManager);
	tileMap.setManager(&manager);
	tileMap.setTileSize(32, 32);
	tileMap.setTileMap(map, mapSize);
	tileMap.setPosition(sf::Vector2f(0, 0));
}

Level::~Level()
{

}

//Setters
void Level::setInput(Input* input) {
	this->input = input;
	manager.setInput(input);
}

void Level::setWindow(sf::RenderWindow* window) {
	this->window = window;
	manager.setWindow(window);
}

void Level::setTextureManager(TextureManager* textureManager) {
	this->textureManager = textureManager;
	manager.setTextureManager(textureManager);
}

void Level::setAudioManager(AudioManager* audioManager) {
	this->audioManager = audioManager;
	manager.setAudioManager(audioManager);
}

void Level::setGameState(GameState* gameState) {
	this->gameState = gameState;
}

//(re)build the level
void Level::buildLevel() {
	manager.deleteEntities();
	tileMap.buildLevel();
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