#include "DiagonalWallL.h"


DiagonalWallL::DiagonalWallL(sf::Vector2f location, const sf::Texture& texture) : Walls(location, texture)
{
	getSprite().setRotation(-45);
}
