#pragma once
//--------------------include Section --------------------
#include "Demons.h"
//--------------------Revenant Class definition --------------------
class Revenant : public Demons
{
public:
	using Demons::Demons;
	Revenant(sf::Vector2f location, const sf::Texture& texture);
	Revenant();
	virtual ~Revenant() = default;


private:

};