#pragma once
//--------------------include Section --------------------
#include "Weapons.h"
//--------------------Pistol Class definition --------------------
class Pistol : public Weapons
{
public:
	using Weapons::Weapons;
	Pistol(sf::Vector2f location, const sf::Texture& texture,
		sf::Vector2f target);
	virtual ~Pistol() = default;

	virtual void draw(sf::RenderWindow& window)override;
	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;
private:
	sf::CircleShape m_bullet;

};
