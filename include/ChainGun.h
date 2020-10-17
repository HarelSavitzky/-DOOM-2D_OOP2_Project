#pragma once
//--------------------include Section --------------------
#include "Weapons.h"
//--------------------ChainGun Class definition --------------------
class ChainGun : public Weapons
{
public:
	using Weapons::Weapons;
	ChainGun(sf::Vector2f location, const sf::Texture& texture,
		sf::Vector2f target);
	virtual ~ChainGun() = default;

	virtual void draw(sf::RenderWindow& window)override;
	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;
private:
	std::vector <sf::CircleShape> m_bullet;

};
