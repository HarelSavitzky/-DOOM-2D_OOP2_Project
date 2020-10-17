#include "StaticObject.h"

StaticObject::StaticObject()
{}
StaticObject::StaticObject(sf::Vector2f location,
	const sf::Texture& texture) : GameObject(location, texture)
{
}