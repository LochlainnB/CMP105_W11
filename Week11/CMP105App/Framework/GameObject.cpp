#include "GameObject.h"

GameObject::GameObject()
{
	input = nullptr;
	setSize(sf::Vector2f(32, 32));
	setCollisionBox(sf::FloatRect(0, 0, 32, 32));
	setCollider(true);
	setName(ObjectName::TERRAIN);
	setAlive(true);
}

GameObject::~GameObject()
{

}

// Override this function to provide input handling for the derived class
void GameObject::handleInput(float dt)
{
}

// override this function to provide functionality
void GameObject::update(float dt)
{
}

// Sets the velocity of the sprite
void GameObject::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}
void GameObject::setVelocity(float vx, float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}

// get sprite velocity
sf::Vector2f GameObject::getVelocity()
{
	return velocity;
}

// Returns collision box + position, giving the collision box in the correct position
sf::FloatRect GameObject::getCollisionBox() {
	
	return sf::FloatRect(collisionBox.left + getPosition().x, collisionBox.top + getPosition().y, collisionBox.width, collisionBox.height); 
}

// Reponse function, what the sprite does based on collision
// Colliding object is passed in for information
// e.g. compare sprite positions to determine new velocity direction.
// e.g. checking sprite type (world, enemy, bullet etc) so response is based on that.
void GameObject::collisionResponse(GameObject * collider)
{
}

// Extra stuff, see header for info
void GameObject::setWindow(sf::RenderWindow* window) {
	this->window = window;
}

void GameObject::setEntities(std::vector<GameObject*>* entities) {
	this->entities = entities;
}

void GameObject::setName(ObjectName name) {
	this->name = name;
}

ObjectName GameObject::getName() {
	return name;
}

void GameObject::setTextureManager(TextureManager* textureManager) {
	this->textureManager = textureManager;
	this->setTexture(textureManager->getTexture(TextureName::TERRAIN));
}

void GameObject::setAudioManager(AudioManager* audioManager) {
	this->audioManager = audioManager;
}