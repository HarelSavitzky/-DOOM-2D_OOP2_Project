#pragma once
//--------------------include Section --------------------
#include "Demons.h"
//--------------------Mancubus Class definition --------------------
class Mancubus : public Demons
{
public:
	using Demons::Demons;
	Mancubus(sf::Vector2f location, const sf::Texture& texture);
	Mancubus();
	virtual ~Mancubus() = default;

private:

};