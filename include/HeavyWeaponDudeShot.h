#pragma once
//--------------------include Section --------------------
#include "Weapons.h"
//--------------------HeavyWeaponDudeShot Class definition --------------------
class HeavyWeaponDudeShot : public Weapons
{
public:
	using Weapons::Weapons;
	HeavyWeaponDudeShot(sf::Vector2f location, const sf::Texture& texture, sf::Vector2f target);
	virtual ~HeavyWeaponDudeShot() = default;


	virtual void draw(sf::RenderWindow& window)override;
	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;

private:
	sf::Sprite m_boomSprite;
	bool m_endExplosion;
	bool m_toExplode;
};
