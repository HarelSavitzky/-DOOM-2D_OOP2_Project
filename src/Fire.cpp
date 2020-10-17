#include "Fire.h"

Fire::Fire()
{}
//--------------- setSpriteSheet function ---------------
//function to set fire animation
void Fire::setSpriteSheet(sf::Time deltaTime)
{
	m_timer += deltaTime;
	if (m_timer.asSeconds() > 0.01)					//set fire sprite sheet
	{
		if (getSpriteSource().x == 7 && getSpriteSource().y == 3)
			setSpriteSource(sf::Vector2f(0, 0));

		if (getSpriteSource().x < 7)
			setSpriteSource(sf::Vector2f(getSpriteSource().x + 1, getSpriteSource().y));
		else
			setSpriteSource(sf::Vector2f(0, getSpriteSource().y + 1));

		m_timer = sf::seconds(0.0);
	}
	getSprite().setTextureRect(sf::IntRect(getSpriteSource().x * 64, getSpriteSource().y * 128, 64, 128));		//set const
	getSprite().setScale(2, 2);
}