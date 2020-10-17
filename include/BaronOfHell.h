#pragma once
//--------------------include Section --------------------
#include "Demons.h"
//--------------------BaronOfHell Class definition --------------------
class BaronOfHell : public Demons
{
public:
	using Demons::Demons;
	BaronOfHell(sf::Vector2f location, const sf::Texture& texture);
	BaronOfHell();
	virtual ~BaronOfHell() = default;
private:

};