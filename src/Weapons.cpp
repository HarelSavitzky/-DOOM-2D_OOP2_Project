#include "Weapons.h"

//---------------Weapons constructor--------------------
Weapons::Weapons(sf::Vector2f location, const sf::Texture& texture,
	sf::Vector2f target) : MovingObject(location, texture)
{
	m_target = target;
	m_currentVelocity = sf::Vector2f(0.f, 0.f);
	m_shootingRange = 600.f;
	m_maxSpeed = 10.f;									//calculates the vector between slayer to demon
	m_aimDir = target - location;
	m_aimDirNorm = m_aimDir / sqrt(pow(m_aimDir.x, 2) + pow(m_aimDir.y, 2));
	setDirection(m_aimDirNorm);
	setShootingDir();
	m_currentVelocity = m_aimDirNorm * m_maxSpeed;	
	setSpriteRotation();
}
//---------------setShootingDir function--------------------
//sets the shooting direction(from 8 directions)
void Weapons::setShootingDir()			
{
	if (m_aimDirNorm.x < 0.5 && m_aimDirNorm.x > -0.8 && m_aimDirNorm.y > 0.4)
		m_shootingDirection = DOWN;
	if (m_aimDirNorm.x > -0.92 && m_aimDirNorm.x < 0 && m_aimDirNorm.y > 0.4 && m_aimDirNorm.y < 0.9)
		m_shootingDirection = DOWN_LEFT;
	if (m_aimDirNorm.x < -0.9 && m_aimDirNorm.y < 0.45 && m_aimDirNorm.y >-0.4)
		m_shootingDirection = LEFT;
	if (m_aimDirNorm.x > -0.92 && m_aimDirNorm.x < 0 && m_aimDirNorm.y > -0.94 && m_aimDirNorm.y < -0.4)
		m_shootingDirection = UP_LEFT;
	if (m_aimDirNorm.x < 0.4 && m_aimDirNorm.x > -0.4 && m_aimDirNorm.y < -0.92)
		m_shootingDirection = UP;
	if (m_aimDirNorm.x < 0.92 && m_aimDirNorm.x > 0.38 && m_aimDirNorm.y < -0.42 && m_aimDirNorm.y > -0.92)
		m_shootingDirection = UP_RIGHT;
	if (m_aimDirNorm.x > 0.89 && m_aimDirNorm.y > -0.45 && m_aimDirNorm.y < 0.45)
		m_shootingDirection = RIGHT;
	if (m_aimDirNorm.x > 0.5 && m_aimDirNorm.x < 0.9 && m_aimDirNorm.y > 0.4 && m_aimDirNorm.y < 0.9)
		m_shootingDirection = DOWN_RIGHT;	
}
//---------------setSpriteRotation function--------------------
//this function setting the rotation of the bullet to the right angle of shooting in the same moment
void Weapons::setSpriteRotation()	
{
	switch (m_shootingDirection)
	{
	case DOWN:
		getSprite().setRotation(SHOT_DOWN);
		break;
	case DOWN_LEFT:
		getSprite().setRotation(SHOT_DOWN_LEFT);
		break;
	case LEFT:
		getSprite().setRotation(SHOT_LEFT);
		break;
	case UP_LEFT:
		getSprite().setRotation(SHOT_UP_LEFT);
		break;
	case UP:
		getSprite().setRotation(SHOT_UP);
		break;
	case UP_RIGHT:
		getSprite().setRotation(SHOT_UP_RIGHT);
		break;
	case RIGHT:
		getSprite().setRotation(SHOT_RIGHT);
		break;
	case DOWN_RIGHT:
		getSprite().setRotation(SHOT_DOWN_RIGHT);
		break;
	}
}
//---------------distance function--------------------
//calculating the distance
float Weapons::distance(sf::Vector2f vec1, sf::Vector2f vec2) {
	return sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2));
}
//---------------endShotMove function--------------------
//ending the shooting
void  Weapons::endShotMove()
{
	if (distance(getStartingPoint(), getObjectPosition()) >= getShootingRange())
	{
		setDelete();
	}
}