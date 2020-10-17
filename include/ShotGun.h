#pragma once
//--------------------include Section --------------------
#include "Weapons.h"
//--------------------ShotGun Class definition --------------------
class ShotGun : public Weapons
{
public:
	using Weapons::Weapons;
	ShotGun(sf::Vector2f location, const sf::Texture& texture,sf::Vector2f target);
	virtual ~ShotGun() = default;

	virtual void draw(sf::RenderWindow& window)override;
	virtual void changeDirection(sf::Time deltaTime)override {};
	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;

private:

};
