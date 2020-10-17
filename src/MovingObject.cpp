#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2f location, const sf::Texture& texture)
	: GameObject(location, texture), m_startingPoint(location)
{
	m_startingPoint = location;
}
//---------------move function--------------------
//function to move the onject
void MovingObject::move(sf::Vector2f direction, sf::Time deltaTime) //move
{
	getSprite().move(direction * deltaTime.asSeconds());
	setDeltaTime(deltaTime);
}
//---------------stopObject function--------------------
//function to stop the object 
void MovingObject::stopObject()	//stop
{
	this->move(-m_direction, getDeltaTime());
	m_isStopped = true;
}
//---------------setDeltaTime function--------------------
//function to set the current deltaTime used by the Object
void MovingObject::setDeltaTime(sf::Time deltaTime)	
{
	m_deltaTime = deltaTime;
}
//---------------setDirection function--------------------
//function to set the object direction
void MovingObject::setDirection(sf::Vector2f direction)
{
	m_direction = direction;
}
//---------------setMovingDirection function--------------------
//function to set the object current moving direction
void MovingObject::setMovingDirection()		
{
	if (getDirection().x == 0 && getDirection().y > 0) // Down
		m_movingDirection = DOWN;
	else if (getDirection().x < 0 && getDirection().y > 0) // Down left
		m_movingDirection = DOWN_LEFT;
	else if (getDirection().x < 0 && getDirection().y == 0) //Left
		m_movingDirection = LEFT;
	else if (getDirection().x < 0 && getDirection().y < 0) //Up Left
		m_movingDirection = UP_LEFT;
	else if (getDirection().x == 0 && getDirection().y < 0) //Up
		m_movingDirection = UP;
	else if (getDirection().x > 0 && getDirection().y > 0) //Down Right
		m_movingDirection = DOWN_RIGHT;
	else if (getDirection().x > 0 && getDirection().y == 0) // Right
		m_movingDirection = RIGHT;
	else if (getDirection().x > 0 && getDirection().y < 0) //Up Right
		m_movingDirection = UP_RIGHT;
}
//---------------getDirection function--------------------
//function to get the object direction
sf::Vector2f MovingObject::getDirection() const
{
	return m_direction;
}
//---------------getStartingPoint function--------------------
//function to get the object starting point
sf::Vector2f MovingObject::getStartingPoint() const
{
	return m_startingPoint;
}
//---------------getDeltaTime function--------------------
//function to get the Current deltaTime
sf::Time MovingObject::getDeltaTime() const
{
	return m_deltaTime;
}