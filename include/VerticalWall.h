#pragma once
//--------------------include Section --------------------
#include "Walls.h"
//--------------------VerticalWall Class definition -------------------- 
class VerticalWall : public Walls
{
public:
	using Walls::Walls;
	VerticalWall();
	virtual ~VerticalWall() = default;

	virtual void setSpriteSheet(sf::Time deltaTime) override;

private:
};