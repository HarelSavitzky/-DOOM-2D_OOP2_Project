
#pragma once
//--------------------include Section --------------------
#include "Walls.h"
//--------------------DiagonalWallL Class definition --------------------
class DiagonalWallL : public Walls
{
public:
	DiagonalWallL(){};
	DiagonalWallL(sf::Vector2f location, const sf::Texture& texture);
	virtual ~DiagonalWallL() = default;

private:
};