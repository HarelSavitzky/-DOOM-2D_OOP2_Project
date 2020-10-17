#include "ShotGunAmmo.h"
ShotGunAmmo::ShotGunAmmo()
{}

ShotGunAmmo::ShotGunAmmo(sf::Vector2f location, const sf::Texture& texture)
	: Ammo(location, texture)
{
	SetSizeOfMag(5);
}