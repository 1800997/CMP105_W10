#pragma once
#include "Framework/TileMap.h"


class MarioTiles
{
public:
	MarioTiles();
	~MarioTiles();

	void render(sf::RenderWindow*);
	TileMap tileMap;
	GameObject tile;
	std::vector<GameObject> tiles;

};

