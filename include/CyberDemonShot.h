#pragma once
//--------------------include Section --------------------
#include "BigBoomWeapons.h"
//--------------------CyberDemonShot Class definition --------------------
class CyberDemonShot : public BigBoomWeapons
{
public:
	using BigBoomWeapons::BigBoomWeapons;
	CyberDemonShot(sf::Vector2f location, const sf::Texture& texture,
		sf::Vector2f target);
	virtual ~CyberDemonShot() = default;

	virtual void setSpriteSheet(sf::Time deltaTime) override {};//??

private:
};
