#include "PlasmaRifleAmmo.h"
PlasmaRifleAmmo::PlasmaRifleAmmo()
{
}
PlasmaRifleAmmo::PlasmaRifleAmmo(sf::Vector2f location, const sf::Texture& texture)
	: Ammo(location, texture)
{
	SetSizeOfMag(15);
}
