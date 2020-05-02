#include "Player.h"
#include <iostream>

Player::Player() {
	setSize(sf::Vector2f(32, 32));
	setCollisionBox(sf::FloatRect(0, 0, 32, 32));
	setCollider(true);
	setName(ObjectName::PLAYER);
	acceleration = sf::Vector2f(0, 980);
	setAlive(true);
}

Player::~Player() {

}

void Player::setAcceleration(sf::Vector2f acceleration) {
	this->acceleration = acceleration;
}

void Player::setAcceleration(float accelerationX, float accelerationY) {
	this->acceleration = sf::Vector2f(accelerationX, accelerationY);
}

sf::Vector2f Player::getAcceleration() {
	return acceleration;
}

void Player::handleInput(float dt) {
	//gravity
	velocity += acceleration * dt;
	//movement
	velocity.x = 0;
	if (input->isKeyDown(22)) {
		velocity.y = -400;
		input->setKeyUp(22);
		audioManager->playSoundbyName("jump");
	}
	if (input->isKeyDown(0)) {
		velocity.x = -200;
	}
	else if (input->isKeyDown(3)) {
		velocity.x = 200;
	}
}

void Player::update(float dt) {
	//max gravity
	if (velocity.y > 1000) {
		velocity.y = 1000;
	}

	//set position
	setPosition(getPosition() + velocity * dt);

	//check collisions
	for (int i = 0; i < entities->size(); i++) {
		if ((*entities)[i]->getName() == ObjectName::TERRAIN && (*entities)[i]->isCollider()) {
			if (Collision::checkBoundingBox(this, (*entities)[i])) {
				collisionResponse((*entities)[i]);
			}
		}
	}
}

void Player::collisionResponse(GameObject* other) {
	//collision with terrain
	if (other->getName() == ObjectName::TERRAIN) {
		//get overlap in X and Y. If overlap greater in X, colliding with top or bottom. Y is opposite
		float lowestX = getPosition().x + getCollisionBox().left;
		float highestX = lowestX + getCollisionBox().width;
		float otherLowestX = other->getPosition().x + other->getCollisionBox().left;
		float otherHighestX = otherLowestX + other->getCollisionBox().width;
		float highestLowX;
		float lowestHighX;
		if (highestX < otherHighestX) {
			lowestHighX = highestX;
		}
		else {
			lowestHighX = otherHighestX;
		}
		if (lowestX > otherLowestX) {
			highestLowX = lowestX;
		}
		else {
			highestLowX = otherLowestX;
		}
		float overlapX = lowestHighX - highestLowX;

		float lowestY = getPosition().y + getCollisionBox().top;
		float highestY = lowestY + getCollisionBox().height;
		float otherLowestY = other->getPosition().y + other->getCollisionBox().top;
		float otherHighestY = otherLowestY + other->getCollisionBox().height;
		float highestLowY;
		float lowestHighY;
		if (highestY < otherHighestY) {
			lowestHighY = highestY;
		}
		else {
			lowestHighY = otherHighestY;
		}
		if (lowestY > otherLowestY) {
			highestLowY = lowestY;
		}
		else {
			highestLowY = otherLowestY;
		}
		float overlapY = lowestHighY - highestLowY;

		if (overlapX <= overlapY + 1) {
			//check left or right
			if (getPosition().x + (getCollisionBox().left - getPosition().y) + getCollisionBox().width / 2 > other->getPosition().x + (other->getCollisionBox().left - other->getPosition().y) + other->getCollisionBox().width / 2) {
				setPosition((other->getCollisionBox().left + other->getCollisionBox().width) - (getCollisionBox().left - getPosition().x), getPosition().y);
			}
			else {
				setPosition(other->getCollisionBox().left - other->getCollisionBox().width, getPosition().y);
			}
			
		}
		else {
			//check top or bottom
			if (getPosition().y + (getCollisionBox().top - getPosition().x) + getCollisionBox().height / 2 > other->getPosition().y + (other->getCollisionBox().top - other->getPosition().x) + other->getCollisionBox().height / 2) {
				//bottom
				setPosition(getPosition().x, (other->getCollisionBox().top + other->getCollisionBox().height) - (getCollisionBox().top - getPosition().y));
				if (velocity.y < 0) {
					velocity.y = 0;
				}
			}
			else {
				//top
				setPosition(getPosition().x, other->getCollisionBox().top - other->getCollisionBox().height);
				if (velocity.y > 0) {
					velocity.y = 0;
				}
			}
		}
	}
}

void Player::setTextureManager(TextureManager* textureManager) {
	this->textureManager = textureManager;
	setTexture(textureManager->getTexture(TextureName::PLAYER));
}