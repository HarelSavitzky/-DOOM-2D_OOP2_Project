#pragma once
//--------------------include Section --------------------
#include "MovingObject.h"

//--------------------Demons Class definition --------------------
class Demons : public MovingObject
{
public:
	using MovingObject::MovingObject;
	Demons();
	Demons(sf::Vector2f location, const sf::Texture& texture);
	virtual ~Demons() = default;

	void setRandDirection();
	void takeDamage(int damage);
	void playDemonActionSound(int action);

	void updateSlayerLocation(sf::Vector2f slayerLocation) { m_slayerLocation = slayerLocation; }
	void updateSlayerDeathStatus() { m_isSlayerAlive = false; };
	void countUntillNextHit(sf::Time deltaTime);

	void setOnView();
	void setfinishDeath() { m_finishDeath = true; };
	void setCanHit(bool canHit) { m_canHit = canHit; };
	void setRandMove() { m_randMove = true; };
	void setIsAShooter() { m_isAShooter = true; };
	void setDamage(int damage) { m_damage = damage; };
	void setSpeed(int speed) { m_speed = speed; };
	void setDirRate(float dirRate) { m_changeDirRate = dirRate; };
	void setDeathFrames(int frames) { m_deathFrames = frames; };
	void setAttackingFrames(int frames) { m_attackingFrames = frames; };
	void setHealth(int health) { m_maxHealth = m_currentHealth = health; };
	void setSwichFrameRate(float frameRate) { m_swichFrameRate = frameRate; };
	void setHittingRate(float hittingRate) { m_hittingRate = hittingRate; };
	void setDeathSource(sf::Vector2f deathSource) { m_deathSource = deathSource; };
	void setAttackingSource(sf::Vector2f attackingSource) { m_attackingSource = attackingSource; };
	void setDemonActionSound(sf::Sound sight, sf::Sound attack, sf::Sound injured, sf::Sound death);
	void setIsAttacking(bool attacking) { m_isAttacking = attacking; m_activateAttackSound = true; };

	float getHittingRate() const { return m_hittingRate; };
	float getChangeDirRate() { return m_changeDirRate; };

	int getHealth() const { return m_currentHealth; };
	int getDamage() const { return m_damage; };
	int getSpeed() const { return m_speed; };
	int getAttackingFrames() const { return m_attackingFrames; };
	int getDeathFrames() const { return m_deathFrames; };

	bool getCanHit() const { return m_canHit; };
	bool getOnView() const{ return m_onView; };
	bool getIsDead() const { return m_isDead; };
	bool getfinishDeath() const { return m_finishDeath; };

	sf::Vector2f getAttackingSource() const {return m_attackingSource;};
	sf::Vector2f getDeathSource() const {return m_deathSource;};
	sf::Vector2f getSlayerLocaion() const { return m_slayerLocation; };

	virtual void setSpriteSheet(sf::Time deltaTime)override;
	virtual void changeDirection(sf::Time deltaTime)override;

private:
	int m_speed;
	int m_currentHealth;
	int m_maxHealth;
	int m_damage;
	int m_damageCount = 0;
	int m_hundredCount = 1;
	int m_attackingFrames;
	int m_deathFrames;
	
	float m_changeDirRate;
	float m_hittingRate;
	float m_swichFrameRate;

	bool m_isDead = false;
	bool m_finishDeath = false;
	bool m_isAttacking = false;
	bool m_randMove = false;
	bool m_onView = false;
	bool m_canHit = true;
	bool m_isSlayerAlive = true;
	bool m_isAShooter = false;
	bool m_activateSightSound = true;
	bool m_activateDeathSound = true;
	bool m_activateAttackSound = true;

	sf::Time m_hittingTimer;
	sf::Time m_movingTimer;
	sf::Time m_changeDirTimer;
	sf::Vector2f m_slayerLocation;
	sf::Vector2f m_attackingSource;
	sf::Vector2f m_deathSource;
	sf::Sound m_sounds[DEMON_ACTION_SOUNDS];

};