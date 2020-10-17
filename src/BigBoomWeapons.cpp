#include "BigBoomWeapons.h"

BigBoomWeapons::BigBoomWeapons(sf::Vector2f location, const sf::Texture& texture,
	sf::Vector2f target): Weapons(location, texture, target)
{
	getSprite().setTexture(texture);
	getSprite().setPosition(location);
	
	setCurrentVelocity(getAimDirNorm() * 22.f);		//set speed to const
	setShootingRange(1200.f);
	m_endExplosion = false;
	m_toExplode = false;
}
//move the big shootings
void BigBoomWeapons::move(sf::Vector2f direction, sf::Time deltaTime)
{
	if (!getToExplode())
	{
		if (!getDeleteStatus())
		{
			getSprite().move(getCurrentVelocity());

			getBoomSprite().setOrigin((getBoomSprite().getTexture()->getSize().x * 0.5),	//set the second sprite on first one
				getBoomSprite().getTexture()->getSize().y * 0.5);

			getSprite().setOrigin((getSprite().getTexture()->getSize().x * 0.5),
				(getSprite().getTexture()->getSize().y * 0.5));

			getBoomSprite().setPosition(getSprite().getPosition().x, getSprite().getPosition().y);
		}
	}
	else
	{
		boomHandle(deltaTime);
	}
	if (distance(getStartingPoint(), getObjectPosition()) >= getShootingRange() ||
		distance(getBoomSprite().getPosition(), getTarget()) <= 20)
	{
		setCurrentVelocity(sf::Vector2f(0, 0));
		setToExplode();
	}
}
//activate the explotion
void BigBoomWeapons::boomHandle(sf::Time deltaTime)
{
	m_explotionTimer += deltaTime;

	if (m_explosionScale == 1 && m_explosionCounter == 0)
		playHitSound();

	setToExplode();
	setSpriteSheet(deltaTime);			//activate boom animation
	getSprite().setRotation(20);

	if (m_explotionTimer.asSeconds() > 0.00001 && m_explosionCounter < getToExplotionSize())
	{
		if (m_explosionCounter % 2 == 0)
			getSprite().setScale(getScalar() * m_explosionScale, getScalar() * m_explosionScale);

		getBoomSprite().setScale(getBoomScalar() * m_explosionScale, getBoomScalar() * m_explosionScale);
		m_explotionTimer = sf::seconds(0.0);
		m_explosionScale++;
		m_explosionCounter++;
	}
	else if (m_explotionTimer.asSeconds() > 0.00001 && m_explosionCounter >= getToExplotionSize())
	{
		if (m_explosionCounter % 2 == 0)
			getSprite().setScale(getScalar() * m_explosionScale, getScalar() * m_explosionScale);

		getBoomSprite().setScale(getBoomScalar() * m_explosionScale, getBoomScalar() * m_explosionScale);
		m_explotionTimer = sf::seconds(0.0);
		m_explosionScale--;
		m_explosionCounter++;
	}
	if (m_explosionCounter > (getToExplotionSize()*2))
	{
		m_explosionScale = 1;
		m_explosionCounter = 0;
		setEndExplotion();
		setDelete();
	}
}
void BigBoomWeapons::setHitSounds( sf::Sound hit)
{
	m_hitSound = hit;
}
void BigBoomWeapons::draw(sf::RenderWindow& window)
{
	window.draw(getSprite());

	if ((distance(getStartingPoint(), getObjectPosition()) >= getShootingRange()) || (m_toExplode))
		window.draw(getBoomSprite());
}