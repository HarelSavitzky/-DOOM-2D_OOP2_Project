#include "SmallHealth.h"

SmallHealth::SmallHealth(sf::Vector2f location,
	const sf::Texture& texture) : Health(location, texture)
{
	setHealth(30);
}

void SmallHealth::setSpriteSheet(sf::Time deltaTime)
{
}
