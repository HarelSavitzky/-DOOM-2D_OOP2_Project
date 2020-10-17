#pragma once
//--------------------include Section --------------------
#include "BigBoomWeapons.h"

//--------------------MancubusShot Class definition --------------------
class MancubusShot : public BigBoomWeapons
{
public:
	using BigBoomWeapons::BigBoomWeapons;
	MancubusShot(sf::Vector2f location, const sf::Texture& texture, sf::Vector2f target);
	virtual ~MancubusShot() = default;

	virtual void setSpriteSheet(sf::Time deltaTime) override;
	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;

private:
	sf::Time m_spriteTimer = sf::seconds(0.0);
};
