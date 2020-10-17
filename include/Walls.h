#pragma once
//--------------------include Section --------------------
#include "StaticObject.h"
//--------------------Walls Class definition -------------------- 
class Walls : public StaticObject
{
public:
	Walls();
	Walls(sf::Vector2f location, const sf::Texture& texture);
	virtual ~Walls() = default;

	virtual void setSpriteSheet(sf::Time deltaTime) override;

private:
};