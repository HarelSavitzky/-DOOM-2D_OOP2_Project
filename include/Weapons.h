#pragma once
//--------------------include Section --------------------
#include "MovingObject.h"
//--------------------Weapons Class definition -------------------- 
class Weapons : public MovingObject
{
public:
	Weapons(sf::Vector2f location, const sf::Texture& texture,
		sf::Vector2f target);
	Weapons() {};
	virtual ~Weapons() = default;

	void setShootingDir();
	void setSpriteRotation();
	void setWeaponDamage(int damage) { m_damage = damage; };
	void setCurrentVelocity(sf::Vector2f currentVelocity) {m_currentVelocity = currentVelocity;};
	void setShootingRange(float shootingRange) { m_shootingRange = shootingRange;};

	//get functions --------------
	int getWeaponDamage() const { return m_damage; };
	float getShootingRange()const { return m_shootingRange; };
	sf::Vector2f getTarget()const { return m_target; };
	sf::Vector2f getCurrentVelocity() const {return m_currentVelocity;};
	sf::Vector2f getAimDirNorm()const { return m_aimDirNorm; };
	Direction getShootingDirection()const { return m_shootingDirection; };
	//--------------

	void  endShotMove();
	float distance(sf::Vector2f vec1, sf::Vector2f vec2);

	virtual void changeDirection(sf::Time deltaTime)override {};	
	virtual void setSpriteSheet(sf::Time deltaTime) override {};
	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override {};
	virtual void draw(sf::RenderWindow& window) = 0;
private:

	int m_damage;
	float m_maxSpeed;
	float m_shootingRange;

	sf::Vector2f m_direction;
	sf::Vector2f m_target;
	sf::Vector2f m_aimDir;
	sf::Vector2f m_aimDirNorm;
	sf::Vector2f m_currentVelocity;

	Direction m_shootingDirection;
};
