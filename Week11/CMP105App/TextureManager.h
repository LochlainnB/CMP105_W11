#pragma once
#include <vector>
#include "Framework/Animation.h"
#include "Framework/Enums.h"

class TextureManager {
public:
	TextureManager();
	~TextureManager();

	sf::Texture* getTexture(TextureName name);
	Animation* getAnimation(AnimationName name);

protected:
	std::vector<sf::Texture*> textures;
	std::vector<Animation*> animations;
};