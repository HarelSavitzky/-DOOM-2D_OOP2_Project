#pragma once
//--------------------include Section --------------------
#include "GameObject.h"
//--------------------MovingObject Class definition --------------------
class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;
	MovingObject(sf::Vector2f location, const sf::Texture& texture);
	MovingObject() {};

	void setMovingDirection();
	void setDirection(sf::Vector2f direction);
	void setDeltaTime(sf::Time deltaTime);
	void setIsStopped(bool stop) { m_isStopped = stop; };
	void setScaleSize(sf::Vector2f size) { m_scaleSize = size; };
	void setRecSize(sf::Vector2f size) { m_RecSize = size; };
	void setWalkingFrames(int walkingFrames) {m_walkingFrames = walkingFrames; };

	//get functions-----------
	sf::Time getDeltaTime() const;

	sf::Vector2f getDirection() const;
	sf::Vector2f getStartingPoint() const;
	sf::Vector2f getScaleSize()const { return m_scaleSize; };
	sf::Vector2f getRecSize()const { return m_RecSize; };

	int getWalkingFrames()const { return m_walkingFrames; };
	bool getIsStopped()const { return m_isStopped; };

	Direction getMovingDirection() const {return m_movingDirection;};

	void stopObject();

	//virtual functions-----------
	virtual void move(sf::Vector2f direction, sf::Time deltaTime);
	virtual void changeDirection(sf::Time deltaTime) = 0;  
	virtual void setSpriteSheet(sf::Time deltaTime) = 0;

private:
	int m_walkingFrames;
	int m_attackingFrames;
	int m_deathFrames;

	bool m_isStopped = false;

	sf::Time m_deltaTime;

	Direction m_movingDirection;

	sf::Vector2f m_direction;
	sf::Vector2f m_startingPoint;
	sf::Vector2f m_RecSize;
	sf::Vector2f m_scaleSize;
	


};