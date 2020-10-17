#pragma once
//--------------------include Section --------------------
#include "Ammo.h"
//--------------------ShotGunAmmo Class definition --------------------
class ShotGunAmmo : public Ammo
{
public:
	ShotGunAmmo();
	ShotGunAmmo(sf::Vector2f location, const sf::Texture& texture);
	virtual ~ShotGunAmmo() = default;

private:
};