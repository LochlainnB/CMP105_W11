#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"

class Player : public GameObject {
public:
	Player();
	~Player();

	void setAcceleration(sf::Vector2f acceleration);
	void setAcceleration(float accelerationX, float accelerationY);
	sf::Vector2f getAcceleration();
	void setTextureManager(TextureManager* textureManager) override;

	void handleInput(float dt) override;
	void update(float dt) override;
	void collisionResponse(GameObject* other);
protected:
	sf::Vector2f acceleration;
	sf::Texture texture;
};