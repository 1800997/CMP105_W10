#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/TileMap.h"
#include <string>
#include <iostream>
#include "MarioTiles.h"
#include "Mario.h"
#include "Framework/Collision.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	MarioTiles marioTiles;

	Mario mario;

	sf::Texture marioTexture;


	int maxX, maxY;
};