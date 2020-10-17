#pragma once
//--------------------include Section --------------------
#include "Health.h"
//--------------------UltraHealth Class definition -------------------- 
class UltraHealth : public Health
{
public:
	UltraHealth() {};
	UltraHealth(sf::Vector2f location,
		const sf::Texture& texture);
	virtual ~UltraHealth() = default;

	virtual void setSpriteSheet(sf::Time deltaTime) override;
private:
};