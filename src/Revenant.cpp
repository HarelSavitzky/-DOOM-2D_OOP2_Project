#include "Revenant.h"

Revenant::Revenant()
{}
//a demon, everything that needs to define him his here, and he uses the generic base calss
//that knows to take all the needed actions 
Revenant::Revenant(sf::Vector2f location, const sf::Texture& texture) :
	Demons(location, texture)
{
	setRecSize(sf::Vector2f(100, 100));
	setScaleSize(sf::Vector2f(1.8, 1.8));
	setWalkingFrames(3);
	getSprite().setTextureRect(sf::IntRect(0, RIGHT * getRecSize().y, getRecSize().x, getRecSize().y));
	getSprite().setScale(getScaleSize().x, getScaleSize().y);
	setDamage(15);
	setHealth(150);
	setDeathSource(sf::Vector2f(0, 900));
	setAttackingSource(sf::Vector2f(0, 3));
	setAttackingFrames(3);
	setDeathFrames(5);
	setSwichFrameRate(0.12);
	setSpeed(250);
	setHittingRate(1.5);
	setDirRate(0.3);
	getSprite().setOrigin(getSprite().getLocalBounds().width, getSprite().getLocalBounds().height);
	setDemonActionSound(*SingleTone::instance().getSound(REVENANT_SIGHT_SOUND).get(),
		*SingleTone::instance().getSound(REVENANT_ATTACK_SOUND).get(),
		*SingleTone::instance().getSound(REVENANT_INJURED_SOUND).get(),
		*SingleTone::instance().getSound(REVENANT_DEATH_SOUND).get());
}

	