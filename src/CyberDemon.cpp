#include "CyberDemon.h"

CyberDemon::CyberDemon()
{
}
//a demon, everything that needs to define him his here, and he uses the generic base calss
//that knows to take all the needed actions 
CyberDemon::CyberDemon(sf::Vector2f location, const sf::Texture& texture) :
	Demons(location, texture)
{
	setRecSize(sf::Vector2f(150, 150));
	setScaleSize(sf::Vector2f(2.5, 2.5));
	setWalkingFrames(4);
	getSprite().setTextureRect(sf::IntRect(0, RIGHT * getRecSize().y, getRecSize().x, getRecSize().y));
	getSprite().setScale(getScaleSize().x, getScaleSize().y);
	setDamage(50);
	setHealth(800);
	setDeathSource(sf::Vector2f(0, 1050));
	setAttackingSource(sf::Vector2f(0, 4));
	setAttackingFrames(3);
	setDeathFrames(9);
	setSpeed(300);
	setHittingRate(3.3);
	setDirRate(0.2);
	setSwichFrameRate(0.12);
	getSprite().setOrigin(getSprite().getLocalBounds().width, getSprite().getLocalBounds().height);
	setIsAShooter();
	SingleTone::instance().getSound(CYBERDEMON_SHOT_SOUND).get()->setVolume(30);;

	getSprite().setOrigin(getSprite().getLocalBounds().width * 0.5, getSprite().getLocalBounds().height * 0.5);

	setDemonActionSound(*SingleTone::instance().getSound(CYBERDEMON_SIGHT_SOUND).get(),
		*SingleTone::instance().getSound(CYBERDEMON_SHOT_SOUND).get(),
		*SingleTone::instance().getSound(CYBERDEMON_INJURED_SOUND).get(),
		*SingleTone::instance().getSound(CYBERDEMON_DEATH_SOUND).get());
}
