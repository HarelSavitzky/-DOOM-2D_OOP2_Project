#include "BaronOfHell.h"

BaronOfHell::BaronOfHell()
{}
//a demon, everything that needs to define him his here, and he uses the generic base calss
//that knows to take all the needed actions 
BaronOfHell::BaronOfHell(sf::Vector2f location, const sf::Texture& texture) :
	Demons(location, texture)
{
	setRecSize(sf::Vector2f(113, 120));
	setScaleSize(sf::Vector2f(2.3, 2.3));
	setWalkingFrames(4);
	getSprite().setTextureRect(sf::IntRect(0, RIGHT * getRecSize().y, getRecSize().x, getRecSize().y));
	getSprite().setScale(getScaleSize().x, getScaleSize().y);
	setDamage(30);
	setHealth(400);
	setDeathSource(sf::Vector2f(0, 960));
	setAttackingSource(sf::Vector2f(0, 4));
	setAttackingFrames(4);
	setDeathFrames(6);
	setSpeed(380);
	setDirRate(0.05);
	setHittingRate(1.5);
	setSwichFrameRate(0.1);
	getSprite().setOrigin(getSprite().getLocalBounds().width, getSprite().getLocalBounds().height);
	setDemonActionSound(*SingleTone::instance().getSound(BARON_SIGHT_SOUND).get(),
		*SingleTone::instance().getSound(BARON_ATTACK_SOUND).get(),
		*SingleTone::instance().getSound(BARON_INJURED_SOUND).get(),
		*SingleTone::instance().getSound(BARON_DEATH_SOUND).get());
}
