#pragma once
//--------------------include Section --------------------
#include "Demons.h"
//--------------------HeavyWeaponDude Class definition --------------------
class HeavyWeaponDude : public Demons
{
public:
	using Demons::Demons;
	//constructor ---------------
	HeavyWeaponDude(sf::Vector2f location, const sf::Texture& texture);
	HeavyWeaponDude();
	virtual ~HeavyWeaponDude() = default;


private:

};
