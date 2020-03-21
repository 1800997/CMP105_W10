#include "MarioTiles.h"


MarioTiles::MarioTiles()
{
	tileMap.loadTexture("gfx/marioTiles.png");

	for (int i = 0; i < 7; i++)
	{
		tile.setSize(sf::Vector2f(64, 64));
		tile.setCollisionBox(0, 0, 64, 64);
		tile.setCollider(true);
		tiles.push_back(tile);
	}
	

	tiles[0].setCollider(false);
	tiles[0].setTextureRect(sf::IntRect(157, 51, 16, 16));
	tiles[1].setTextureRect(sf::IntRect(0, 0, 16, 16));
	tiles[2].setTextureRect(sf::IntRect(17, 0, 16, 16));
	tiles[3].setTextureRect(sf::IntRect(34, 0, 16, 16));
	tiles[4].setTextureRect(sf::IntRect(0, 34, 16, 16));
	tiles[5].setTextureRect(sf::IntRect(17, 34, 16, 16));
	tiles[6].setTextureRect(sf::IntRect(34, 34, 16, 16));

	tileMap.setTileSet(tiles);

	sf::Vector2u mapSize(30, 6);

	std::vector<int> map =
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,1,2,2,2,3,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,
		1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,0,0,1,2,3,0,0,
		4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,0,0,4,5,6,0,0
	};

	tileMap.setTileMap(map, mapSize);
	tileMap.setPosition(sf::Vector2f(0, 408));
	tileMap.buildLevel();
}

MarioTiles::~MarioTiles()
{


}

void MarioTiles::render(sf::RenderWindow* window)
{
	tileMap.render(window);
}

