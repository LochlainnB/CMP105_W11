#include "TextureManager.h"

TextureManager::TextureManager() {
	//load all the textures
	//PLAYER
	textures.push_back(new sf::Texture());
	textures[textures.size() - 1]->loadFromFile("gfx/MushroomTrans.png");
	//TERRAIN
	textures.push_back(new sf::Texture());
	textures[textures.size() - 1]->loadFromFile("gfx/Beach_Ball.png");

	//load all the animations
}

TextureManager::~TextureManager() {
	for (int i = 0; i < textures.size(); i++) {
		delete textures[i];
	}
	for (int i = 0; i < animations.size(); i++) {
		delete animations[i];
	}
}

sf::Texture* TextureManager::getTexture(TextureName name) {
	return textures[static_cast<int>(name)];
}

Animation* TextureManager::getAnimation(AnimationName name) {
	return animations[static_cast<int>(name)];
}