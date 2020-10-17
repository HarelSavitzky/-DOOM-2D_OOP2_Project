#pragma once
//--------------------include Section --------------------
#include "Ammo.h"
//--------------------PistolAmmo Class definition --------------------
class PistolAmmo : public Ammo
{
public:
	PistolAmmo();
	PistolAmmo(sf::Vector2f location, const sf::Texture& texture);

	virtual ~PistolAmmo() = default;

private:
};