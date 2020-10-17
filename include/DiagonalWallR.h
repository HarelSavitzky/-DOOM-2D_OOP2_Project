
#pragma once
//--------------------include Section --------------------
#include "Walls.h"

//--------------------DiagonalWallR Class definition --------------------
class DiagonalWallR : public Walls
{
public:
	DiagonalWallR() {};
	DiagonalWallR(sf::Vector2f location, const sf::Texture& texture);
	virtual ~DiagonalWallR() = default;

private:
};