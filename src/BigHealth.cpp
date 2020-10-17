#include "BigHealth.h"

BigHealth::BigHealth(sf::Vector2f location,
	const sf::Texture& texture) : Health(location, texture)
{
	setHealth(60);
}
void BigHealth::setSpriteSheet(sf::Time deltaTime)
{
}
