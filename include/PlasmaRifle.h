#pragma once
//--------------------include Section --------------------
#include "Weapons.h"
//--------------------PlasmaRifle Class definition --------------------
class PlasmaRifle : public Weapons
{
public:
	using Weapons::Weapons;
	PlasmaRifle(sf::Vector2f location, const sf::Texture& texture,
		sf::Vector2f target);
	virtual ~PlasmaRifle() = default;

	virtual void draw(sf::RenderWindow& window)override;
	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;

private:

};
