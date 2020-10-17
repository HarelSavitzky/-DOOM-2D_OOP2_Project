#pragma once
//--------------------include Section --------------------
#include "Health.h"
//--------------------SmallHealth Class definition -------------------- 
class SmallHealth : public Health
{
public:
	SmallHealth() {};
	SmallHealth(sf::Vector2f location,
		const sf::Texture& texture);
	
	virtual ~SmallHealth() = default;

	virtual void setSpriteSheet(sf::Time deltaTime) override;

private:
};