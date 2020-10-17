#include "Armor.h"
Armor::Armor()
{
}
Armor::Armor(sf::Vector2f location, const sf::Texture& texture)
	: StaticObject(location, texture)
{
}