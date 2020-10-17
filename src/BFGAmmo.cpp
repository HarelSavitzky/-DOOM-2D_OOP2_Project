#include "BFGAmmo.h"
BFGAmmo::BFGAmmo()
{	
}

BFGAmmo::BFGAmmo(sf::Vector2f location, const sf::Texture& texture)
	: Ammo(location, texture)
{
	SetSizeOfMag(2);
}
