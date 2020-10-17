#pragma once
//--------------------include Section --------------------
#include "StaticObject.h"

//--------------------Fire Class definition --------------------
class Fire : public StaticObject
{
public:
	using StaticObject::StaticObject;
	Fire();
	virtual ~Fire() = default;
	virtual void setSpriteSheet(sf::Time deltaTime) override;
	int getDamage() { return m_damage; };
private:
	sf::Time m_timer = sf::seconds(0.0);
	int m_damage = 10;
};