#include "Walls.h"
Walls::Walls()
{}

Walls::Walls(sf::Vector2f location, const sf::Texture & texture)
	: StaticObject(location, texture)
{
}

void Walls::setSpriteSheet(sf::Time deltaTime)
{
}
