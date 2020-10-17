#include "Pistol.h"

//class for pistol weapon , will get most of his attributes 
//and actions from weapon function - his base class

//---------------pistol constructor-------------------
Pistol::Pistol(sf::Vector2f location, const sf::Texture& texture,
	sf::Vector2f target) : Weapons(location, texture,target)
{
	getSprite().setTexture(texture);
	getSprite().setPosition(location);	
	getSprite().setScale(0.6, 0.6);
	setCurrentVelocity(getAimDirNorm() * 25.f);
	setShootingRange(700.f);
	setDirection(getCurrentVelocity());
	setWeaponDamage(30);
}
//---------------move function--------------------
//funciton to move the pistol bullet
void Pistol::move(sf::Vector2f direction, sf::Time deltaTime)
{
	if (!getDeleteStatus())
	{
		getSprite().move(getCurrentVelocity());	
		setSpriteRotation();
	}
	endShotMove();
}
//---------------draw function--------------------
//function to draw pistol bullet
void Pistol::draw(sf::RenderWindow& window)
{
	window.draw(getSprite());
}
