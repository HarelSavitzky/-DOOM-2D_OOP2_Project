#pragma once
//--------------------include Section --------------------
#include "Demons.h"

class CyberDemon : public Demons
{
public:
	using Demons::Demons;
	//constructor ---------------
	CyberDemon(sf::Vector2f location, const sf::Texture& texture);
	CyberDemon();
	virtual ~CyberDemon() = default;
private:

};