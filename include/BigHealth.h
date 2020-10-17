#pragma once
//--------------------include Section --------------------
#include "Health.h"
//--------------------BigHealth Class definition --------------------
class BigHealth : public Health
{
public:
	BigHealth() {};
	BigHealth(sf::Vector2f location,
			const sf::Texture& texture);
	virtual ~BigHealth() = default;
	virtual void setSpriteSheet(sf::Time deltaTime) override;
private:
};