#pragma once
//--------------------include Section --------------------
#include "StaticObject.h"

//--------------------Armor Class definition --------------------
class Armor : public StaticObject
{
public:
	Armor();
	Armor(sf::Vector2f location, const sf::Texture& texture);
	virtual ~Armor() = default;
	int getArmor() { return m_armor; };

private:
	int m_armor = 100;
};