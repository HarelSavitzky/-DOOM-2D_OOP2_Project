#pragma once
//--------------------include Section --------------------
#include "StaticObject.h"

//--------------------Health Class definition --------------------
class Health : public StaticObject
{
public:
	using StaticObject::StaticObject;
	Health();
	virtual ~Health() = default;
	Health(sf::Vector2f location,
		const sf::Texture& texture);

	void setHealth(int health) { m_currentHealth = health; };
	int getHealth() { return m_currentHealth; };

	virtual void setSpriteSheet(sf::Time deltaTime) override;

private:
	int m_currentHealth;
};