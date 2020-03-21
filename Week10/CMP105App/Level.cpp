#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	mario.setInput(in);
	// initialise game objects
	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setTexture(&marioTexture);
	mario.setSize(sf::Vector2f(60, 80));
	mario.setCollisionBox(sf::FloatRect(0, 0, 60, 80));
	mario.setPosition(0,0);
	mario.setVelocity(500, 100);
	mario;

	maxX = window->getSize().x;
	maxY = window->getSize().y;
	marioTiles.tileMap.setPosition(sf::Vector2f(0, 0));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	mario.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	
	
	std::vector<GameObject>* world = marioTiles.tileMap.getLevel(); 
	
	for (int i = 0; i < (int)world->size(); i++) 
	{
		if((*world)[i].isCollider())
		{
			if(Collision::checkBoundingBox(&mario, &(*world)[i]))
			{
				mario.collisionResponse(&(*world)[i]);
			}
			
		}

	}
	mario.update(dt,maxY);
	mario.setCollider(false);

}

// Render level
void Level::render()
{
	beginDraw();
	marioTiles.render(window);
	window->draw(mario);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}