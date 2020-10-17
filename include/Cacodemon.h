#pragma once
//--------------------include Section --------------------
#include "Demons.h"
//--------------------Cacodemon Class definition --------------------
class Cacodemon : public Demons
{
public:
	using Demons::Demons;
	//constructor ---------------
	Cacodemon(sf::Vector2f location, const sf::Texture& texture);
	Cacodemon();
	virtual ~Cacodemon() = default;

private:

};