#pragma once
//--------------------include Section --------------------
#include "Ammo.h"
//--------------------PlasmaRifleAmmo Class definition --------------------
class PlasmaRifleAmmo : public Ammo
{
public:
	PlasmaRifleAmmo();
	PlasmaRifleAmmo(sf::Vector2f location, const sf::Texture& texture);

	virtual ~PlasmaRifleAmmo() = default;


private:
};