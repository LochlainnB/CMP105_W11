#include "TileMap.h"
#include <iostream>

// Constructor sets default position value.
TileMap::TileMap()
{
	position = sf::Vector2f(0, 0);
}

TileMap::~TileMap()
{
}

// Receives an array of GameObjects representing the tile set (in order)
void TileMap::setTileSet(std::vector<GameObject> ts)
{
	tileSet = ts;
}

// Receives and array of integers and map dimensions representing the map (where and what tiles to place).
void TileMap::setTileMap(std::vector<int> tm, sf::Vector2u mapDimensions)
{
	tileMap = tm;
	mapSize = mapDimensions;
}

void TileMap::setTileSize(sf::Vector2f tileSize) {
	this->tileSize = tileSize;
}

void TileMap::setTileSize(float tileSizeX, float tileSizeY) {
	this->tileSize = sf::Vector2f(tileSizeX, tileSizeY);
}

// Sets entity manager pointer
void TileMap::setManager(Manager* manager) {
	this->manager = manager;
}

// Once provided with the map and tile set, builds the level, creating an array of tile sprites positioned based on the map. Ready to render.
void TileMap::buildLevel()
{
	if (tileSet.size() > 0 && tileMap.size() > 0)
	{
		int x, y = 0;

		for (int i = 0; i < (int)tileMap.size(); i++)
		{
			x = i % mapSize.x;
			y = (int)floor(i / mapSize.x);
			tileSet[tileMap[i]].setPosition(position.x + (x * tileSize.x), position.y + (y * tileSize.y));
			manager->spawnTile(tileSet[tileMap[i]]);
		}
	}
}