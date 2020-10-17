#pragma once
//--------------------include Section --------------------
#include "Ammo.h"
//--------------------ChainGunAmmo Class definition --------------------
class ChainGunAmmo : public Ammo
{
public:
	ChainGunAmmo();
	ChainGunAmmo(sf::Vector2f location, const sf::Texture& texture);
	virtual ~ChainGunAmmo() = default;
private:
};