#include "Mario.h"

Mario::Mario()
{
	walk.addFrame(sf::IntRect(0, 0, 15, 20));
	walk.addFrame(sf::IntRect(15, 0, 15, 20));
	walk.addFrame(sf::IntRect(30, 0, 15, 20));
	walk.addFrame(sf::IntRect(45, 0, 15, 20));
	walk.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());

	scale = 200.0f;
	gravity = sf::Vector2f(velocity.x, 9.8f) * scale;
	jumpVector = sf::Vector2f(velocity.x, -6.0f) * scale;
	isJumping = false;
	
};

Mario::~Mario()
{



};
void Mario::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation->setFlipped(false);
		currentAnimation->animate(dt);
		setTextureRect(walk.getCurrentFrame());
		move(sf::Vector2f(velocity.x, 0)*dt);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation->setFlipped(true);
		currentAnimation->animate(dt);
		setTextureRect(walk.getCurrentFrame());
		move(sf::Vector2f(-velocity.x, 0) * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{

	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
			sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
			stepVelocity += gravity * dt;
			setPosition(getPosition() + pos);
		}
	}

}

void Mario::update(float dt,int maxY)
{
	if (!collider)
	{
		sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
		stepVelocity += gravity * dt;
		setPosition(getPosition() + pos);
	}

	if (getPosition().y >= maxY)
	{
		setPosition(0,0);

	}
};

void Mario::collisionResponse(GameObject* collider)
{
	setCollider(true);
	isJumping = false;
	stepVelocity = sf::Vector2f(0, 0);
};
