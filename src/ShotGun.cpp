#include "ShotGun.h"
//class for ShotGun weapon , will get most of his attributes 
//and actions from weapon function - his base class

//---------------ShotGun constructor--------------------
ShotGun::ShotGun(sf::Vector2f location, const sf::Texture& texture,
	sf::Vector2f target) : Weapons(location, texture,target)
{
	getSprite().setTexture(texture);
	getSprite().setPosition(location);
	getSprite().setScale(0.5, 0.5);
	getSprite().setOrigin(getSprite().getLocalBounds().width * 0.5,
		getSprite().getLocalBounds().height);
	setCurrentVelocity(getAimDirNorm() * 1.5f);
	setShootingRange(10.f);
	setWeaponDamage(100);
}
//---------------move function--------------------
//funciton to move the ShotGun bullet
void ShotGun::move(sf::Vector2f direction, sf::Time deltaTime)
{
	if (!getDeleteStatus())
	{
		getSprite().move(getCurrentVelocity());
		setSpriteRotation();
	}
	endShotMove();

}
//---------------draw function--------------------
//funciton to draw the ShotGun bullet
void ShotGun::draw(sf::RenderWindow& window)
{
	window.draw(getSprite());
}
