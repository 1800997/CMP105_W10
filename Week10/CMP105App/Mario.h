#pragma once
#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario : public GameObject
{
public:
	Mario();
	~Mario();

	float scale;
	sf::Vector2f jumpVector;
	bool isJumping;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;

	void handleInput(float);
	void update(float,int);
	void collisionResponse(GameObject*);
protected:
	Animation walk;
	Animation* currentAnimation;
};


