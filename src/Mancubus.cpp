#include "Mancubus.h"

Mancubus::Mancubus()
{
}
//a demon, everything that needs to define him his here, and he uses the generic base calss
//that knows to take all the needed actions 
Mancubus::Mancubus(sf::Vector2f location, const sf::Texture& texture) :
	Demons(location, texture)
{
	setRecSize(sf::Vector2f(110, 90));
	setScaleSize(sf::Vector2f(3.5, 3.5));
	setWalkingFrames(6);
	getSprite().setTextureRect(sf::IntRect(0, RIGHT * getRecSize().y, getRecSize().x, getRecSize().y));
	getSprite().setScale(getScaleSize().x, getScaleSize().y);
	setDamage(100);
	setHealth(800);
	setDeathSource(sf::Vector2f(0, 990));
	setAttackingSource(sf::Vector2f(0, 6));
	setAttackingFrames(3.3);
	setDeathFrames(8);
	setSpeed(100);
	setHittingRate(3.0f);
	setSwichFrameRate(0.15);
	setDirRate(0.3);
	getSprite().setOrigin(getSprite().getLocalBounds().width, getSprite().getLocalBounds().height);
	setIsAShooter();
	getSprite().setOrigin(getSprite().getLocalBounds().width * 0.5, getSprite().getLocalBounds().height * 0.5);
	setDemonActionSound(*SingleTone::instance().getSound(MANCUBUS_SIGHT_SOUND).get(),
		*SingleTone::instance().getSound(MANCUBUS_ATTACK_SOUND).get(),
		*SingleTone::instance().getSound(MANCUBUS_INJURED_SOUND).get(),
		*SingleTone::instance().getSound(MANCUBUS_DEATH_SOUND).get());
}
