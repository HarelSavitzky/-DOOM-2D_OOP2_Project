#include "ChainGunAmmo.h"
ChainGunAmmo::ChainGunAmmo()
{
}
ChainGunAmmo::ChainGunAmmo(sf::Vector2f location, const sf::Texture& texture)
	: Ammo(location, texture)
{
	SetSizeOfMag(30);
}
