// Tile Map Class
// This class represents a Tile Map environment for rendering.
// Builds and store level sections based on Map and TileSet
// @author Paul Robertson

#pragma once
#include <math.h>
#include "GameObject.h"
#include "..//Manager.h"

class TileMap
{
public:
	TileMap();
	~TileMap();

	// Receives an array of GameObjects representing the tile set (in order)
	void setTileSet(std::vector<GameObject> ts);
	// Receives and array of integers and map dimensions representing the map (where and what tiles to place).
	void setTileMap(std::vector<int> tm, sf::Vector2u mapDimensions);
	// Sets tile size (note that this isn't the size of the actual tiles, but the distance between their origins)
	void setTileSize(sf::Vector2f tileSize);
	// Sets tile size (note that this isn't the size of the actual tiles, but the distance between their origins)
	void setTileSize(float tileSizeX, float tileSizeY);
	// Once provided with the map and tile set, builds the level, creating an array of tile sprites positioned based on the map. Ready to render.
	void buildLevel();

	// Set the origin position of the tilemap section. 
	void setPosition(sf::Vector2f pos) { position = pos; };

	// Set the manager
	void setManager(Manager* manager);

protected:
	std::vector<GameObject> tileSet;
	std::vector<int> tileMap;
	sf::Vector2f tileSize;
	sf::Texture texture;
	sf::Vector2u mapSize;
	sf::Vector2f position;
	Manager* manager;
};

