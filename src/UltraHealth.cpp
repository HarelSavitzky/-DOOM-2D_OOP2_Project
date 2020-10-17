#include "UltraHealth.h"

UltraHealth::UltraHealth(sf::Vector2f location,
	const sf::Texture& texture) : Health(location, texture)
{
	setHealth(900);
}
void UltraHealth::setSpriteSheet(sf::Time deltaTime)
{
}
