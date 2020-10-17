#include "Health.h"
Health::Health()
{}

void Health::setSpriteSheet(sf::Time deltaTime)
{
}
Health::Health(sf::Vector2f location,
	const sf::Texture& texture) : StaticObject(location, texture)
{
}