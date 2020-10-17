#include "PistolAmmo.h"
PistolAmmo::PistolAmmo()
{
}
PistolAmmo::PistolAmmo(sf::Vector2f location, const sf::Texture& texture)
	: Ammo(location, texture)
{
	SetSizeOfMag(10);
}
