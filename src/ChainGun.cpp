#include "ChainGun.h"

ChainGun::ChainGun(sf::Vector2f location, const sf::Texture& texture
	,sf::Vector2f target) : Weapons(location, texture,target)
{
	getSprite().setTexture(texture);
	getSprite().setPosition(location);
	getSprite().setScale(0.12, 0.12);
	setCurrentVelocity(getAimDirNorm() * 25.f);
	setShootingRange(1100.f);
	setWeaponDamage(10);
}
void ChainGun::move(sf::Vector2f direction, sf::Time deltaTime)
{
	if (!getDeleteStatus())
	{
		getSprite().move(getCurrentVelocity());
		setSpriteRotation();
	}
	endShotMove();
}
void ChainGun::draw(sf::RenderWindow& window)
{
	window.draw(getSprite());
}

