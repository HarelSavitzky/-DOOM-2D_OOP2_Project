#pragma once
//--------------------include Section --------------------
#include "MovingObject.h"
#include "Weapons.h"
#include <list>
#include <vector>
//--------------------Slayer Class definition -------------------- 
class Slayer : public MovingObject
{
public:
	using MovingObject::MovingObject;	
	Slayer(sf::Vector2f location, const sf::Texture& texture);
	virtual  ~Slayer() = default;

	void initializeAmmo();
	void changeDirection(sf::Time deltaTime) override;
	void setIsShooting(bool isShooting) {m_isShooting = isShooting;};
	void setShootingDirection(Direction shootingDir) { m_shootingDirection = shootingDir; };
	void setCurrentWeapon(Weapon weapon) {m_weapon = weapon;};
	void countUntillNextHit(sf::Time deltaTime);
	void takeDamage(int damage);
	bool pickArmor(int armor);
	bool pickHealth(int health);
	void setGetBurned() { m_canGetBurn = false; }
	bool pickAmmo(Weapon weapon, int ammo);
	void updateShooting(Weapon weapon);
	void setIsDashing(bool dash) { m_isDashing = dash; };

	//get functions----------
	int getDashTimer();
	int getHealth() const { return m_health; };
	int getArmor() const { return m_armor; };
	int getWeaponAmmo(Weapon weapon) const { return m_ammo[weapon]; };
	bool getFinishedDying() const { return m_finishedDying; };
	bool getIsDashing() const{ return m_isDashing; };
	bool getIsDead() const { return m_isDead; };
	bool getCanGetBurned() const { return m_canGetBurn; }
	Weapon getCurrentWeapon() const { return m_weapon; };
	//-----------

	virtual void setSpriteSheet(sf::Time deltaTime) override;

private:
	int m_ammo[NUM_OF_WEAPONS];
	int m_maxAmmo[NUM_OF_WEAPONS];
	int m_movingRate;
	int m_health;
	int m_maxHealth;
	int m_armor;
	int m_maxArmor;
	int m_dashCounter = 0;

	bool m_isShooting;
	bool m_isDashing = false;
	bool m_finishShooting;
	bool m_isDead;
	bool m_finishedDying = false;
	bool m_canGetBurn = true;
	bool m_canMakeInjuredSound = true;

	Weapon m_weapon;
	Direction m_shootingDirection;
	sf::Time m_canDashTimer = sf::seconds(0.0);
	sf::Time m_injuredSoundTimer = sf::seconds(0.0);
};