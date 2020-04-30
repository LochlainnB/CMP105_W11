#include "TileSet.h"
//include all the game objects you need
#include "Player.h"

TileSet::TileSet() {
	//textures
	//terrain
	textures.push_back(sf::Texture());
	textures[0].loadFromFile("gfx/marioTiles.png");

	//setup properties and add to tiles
	for (int i = 0; i < 72; i++) {
		GameObject tile;
		tile.setSize(sf::Vector2f(32, 32));
		tile.setCollisionBox(0, 0, 32, 32);
		tile.setCollider(true);
		tile.setTexture(&textures[0]);
		tiles.push_back(tile);
	}

	//set air to not collide;
	tiles[47].setCollider(false);

	//load textures from sprite sheet (if it's a single image, no need for sheet)
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			tiles[(i * 12) + j].setTextureRect(sf::IntRect(j * 17, i * 17, 16, 16));
		}
	}
}

TileSet::~TileSet() {

}

std::vector<GameObject> TileSet::getTiles() {
	return tiles;
}