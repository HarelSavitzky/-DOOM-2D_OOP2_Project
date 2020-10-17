#include "PlasmaRifle.h"

//class for PlasmaRifle weapon , will get most of his attributes 
//and actions from weapon function - his base class

//---------------PlasmaRifle constructor--------------------
PlasmaRifle::PlasmaRifle(sf::Vector2f location, const sf::Texture& texture,
	sf::Vector2f target) : Weapons(location, texture, target)
{
	getSprite().setTexture(texture);
	getSprite().setPosition(location);
	getSprite().setScale(0.3, 0.3);

	setCurrentVelocity(getAimDirNorm() * 15.f);
	setShootingRange(1400.f);
	setWeaponDamage(40);
}
//---------------move function--------------------
//funciton to move the PlasmaRifle bullet
void PlasmaRifle::move(sf::Vector2f direction, sf::Time deltaTime)
{
	if (!getDeleteStatus())
	{
		getSprite().move(getCurrentVelocity());
	}
	endShotMove();
}
//---------------draw function--------------------
//funciton to draw the PlasmaRifle bullet
void PlasmaRifle::draw(sf::RenderWindow& window)
{
	window.draw(getSprite());
}

