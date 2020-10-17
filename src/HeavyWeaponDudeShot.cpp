#include "HeavyWeaponDudeShot.h"
#include "SingleTone.h"

HeavyWeaponDudeShot::HeavyWeaponDudeShot(sf::Vector2f location, const sf::Texture& texture,
	sf::Vector2f target) : Weapons(location, texture,target)
{
	getSprite().setTexture(texture);
	getSprite().setPosition(location);			//initilize the shooting of the heavy weapon dude		
	getSprite().setScale(0.3, 0.3);
	getSprite().setOrigin(getSprite().getLocalBounds().width,
		getSprite().getLocalBounds().height);
	setCurrentVelocity(getAimDirNorm() * 10.f);
	setShootingRange(800.f);
	setDirection(getCurrentVelocity());
	setWeaponDamage(15);
}
//--------------- move function ---------------
//move the HeavyWeaponDudeShot
void HeavyWeaponDudeShot::move(sf::Vector2f direction, sf::Time deltaTime)
{
	if (!getDeleteStatus())
	{
		getSprite().move(getCurrentVelocity());
		setSpriteRotation();
	}
	endShotMove();
}

void HeavyWeaponDudeShot::draw(sf::RenderWindow& window)
{
	window.draw(getSprite());
}

