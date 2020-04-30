#pragma once
#include "Framework/GameObject.h"
#include <vector>

class TileSet {
public:
	//set up tile set
	TileSet();
	~TileSet();

	std::vector<GameObject> getTiles();

protected:
	std::vector<GameObject> tiles;
	std::vector<sf::Texture> textures;
};