#pragma once
//--------------------include Section --------------------
#include "Ammo.h"
//--------------------BFGAmmo Class definition --------------------
class BFGAmmo : public Ammo
{
public:
	BFGAmmo();
	BFGAmmo(sf::Vector2f location,
		const sf::Texture& texture);
	virtual ~BFGAmmo() = default;
private:
};