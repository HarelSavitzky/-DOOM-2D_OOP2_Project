#include "HeavyWeaponDude.h"

HeavyWeaponDude::HeavyWeaponDude()
{
}
//a demon, everything that needs to define him his here, and he uses the generic base calss
//that knows to take all the needed actions 
HeavyWeaponDude::HeavyWeaponDude(sf::Vector2f location, const sf::Texture& texture) :
	Demons(location, texture)
{
	setRecSize(sf::Vector2f(80, 80));
	setScaleSize(sf::Vector2f(2.5, 2.5));
	setWalkingFrames(4);
	getSprite().setTextureRect(sf::IntRect(0, RIGHT * getRecSize().y, getRecSize().x, getRecSize().y));
	getSprite().setScale(getScaleSize().x, getScaleSize().y);
	setDamage(20);
	setHealth(180);
	setDeathSource(sf::Vector2f(0, 560));
	setAttackingSource(sf::Vector2f(0, 4));
	setAttackingFrames(3);
	setDeathFrames(7);
	setSpeed(100);
	setIsAShooter();
	setHittingRate(2);
	setSwichFrameRate(0.12);
	setDirRate(0.3);
	getSprite().setOrigin(getSprite().getLocalBounds().width * 0.5, getSprite().getLocalBounds().height * 0.5);
	setDemonActionSound(*SingleTone::instance().getSound(H_W_D_SIGHT_SOUND).get(),
		*SingleTone::instance().getSound(H_W_D_ATTACK_SOUND).get(),
		*SingleTone::instance().getSound(H_W_D_INJURED_SOUND).get(),
		*SingleTone::instance().getSound(H_W_D_DEATH_SOUND).get());
}