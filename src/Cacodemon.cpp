#include "Cacodemon.h"

Cacodemon::Cacodemon()
{
}
//a demon, everything that needs to define him his here, and he uses the generic base calss
//that knows to take all the needed actions 
Cacodemon::Cacodemon(sf::Vector2f location, const sf::Texture& texture) :
	Demons(location, texture)
{
	setRecSize(sf::Vector2f(90, 90));
	setScaleSize(sf::Vector2f(2.4, 2.4));
	setWalkingFrames(4);
	getSprite().setTextureRect(sf::IntRect(0, RIGHT * getRecSize().y, getRecSize().x, getRecSize().y));
	getSprite().setScale(getScaleSize().x, getScaleSize().y);
	setDamage(45);
	setHealth(350);
	setDeathSource(sf::Vector2f(0, 540));
	setAttackingSource(sf::Vector2f(0, 3));
	setAttackingFrames(2);
	setDeathFrames(6);
	setSpeed(130);
	setHittingRate(0.7);
	setDirRate(0.2);
	setSwichFrameRate(0.12);
	getSprite().setOrigin(getSprite().getLocalBounds().width, getSprite().getLocalBounds().height);
	setDemonActionSound(*SingleTone::instance().getSound(CACODEMON_SIGHT_SOUND).get(),
		*SingleTone::instance().getSound(CACODEMON_ATTACK_SOUND).get(),
		*SingleTone::instance().getSound(CACODEMONE_INJURED_SOUND).get(),
		*SingleTone::instance().getSound(CACODEMON_DEATH_SOUND).get());
}
